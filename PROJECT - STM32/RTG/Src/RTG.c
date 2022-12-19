#include "RTG.h"

uint8_t time_flag = 0;							//Flag when TIME encounters an interrupt event
uint8_t user_on_time_flag = 0;					//Flag when we are on the time or ADC test
uint8_t user_on_ADC_flag = 0;					//Flag when we are on the time or ADC test
uint8_t adc_flag = 0;							//Flag when ADC  encounters an interrupt event
uint8_t ticked_clock_counter = 0;				//Counter ticking clock when we are working on protocol.
uint8_t ticked_clock_flag = 0;					//Flag when we are working on protocol.
uint16_t YearStart = 2000;						//Year start to adding to RTC's year
uint8_t is_on_UART = 0;							//Flag when working on UART

/*
 * ADC: PA0/WKUP (CN10)
 * I2C1 (MASTER): PB8 (CN7) - I2C1_SCL, PB9 (CN7) - I2C1_SDA
 * I2C2 (SLAVE): PF0 (CN9) - I2C2_SDA, PF1 (CN9) - I2C1_SCL; Slave address: 44
 * SPI2 (MASTER): PB10 (CN10) - SPI2_SCK, PC2 (CN10) - SPI2_MISO, PC3 (CN9) - SPI2_MOSI
 * SPI3 (SLAVE): PB2 (CN10) - SPI3_MOSI, PC10 (CN8) - SPI3_SCK, PC11 (CN8) - SPI3_MISO
 * UART5: PC12 (CN8) - UART5_TX, PD2 (CN8) - UART5_RX
 * USART6: PC6 (CN7) - USART6_TX, PC7 (CN7) - USART6_RX
 * Client: 192.168.0.123; Port: 7
 */

//main function
void rtg_main() {
	printf("\r\n"PURPLE"Start of program:"BLACK"\r\n");

	udpServer_init();

	HAL_TIM_Base_Start_IT(TIM_3); // Initiate timer 3
	int current_test_number = 0; // current test number

	//Time Data
	RTC_TimeTypeDef sTime; // RTC's time
	RTC_DateTypeDef sDate; // RTC's Date

	// Set date and time (I set it on 27/11/2022 in 19:20)
	sDate.WeekDay = RTC_WEEKDAY_MONDAY; // day of the date (name)
	sDate.Date = 28; // setting the day of the date (number; from 1-31 depends on the month)
	sDate.Month = 11; // setting the month of the date (1-12)
	sDate.Year = 22; // setting the year of the date; from 0-99 (2022 == 22, start year = 2000)
	HAL_RTC_SetDate(RtcHandle, &sDate, RTC_FORMAT_BIN); // setting the date in RTC mode
	sTime.Hours = 9; // setting the hours
	sTime.Minutes = 0; // setting the minutes
	HAL_RTC_SetTime(RtcHandle, &sTime, RTC_FORMAT_BIN); // setting the time in RTC mode

	// Start Wakeup timer with configuration (32768Hz / 16 = 2048) -> Counter = 2048
	HAL_RTCEx_SetWakeUpTimer_IT(RtcHandle, 2048-1, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

	while(1) {
		ethernetif_input(&gnetif); // enter to gnetif the input from client
		sys_check_timeouts(); // check timeouts of the system
		current_test_number++; // add 1 to the current test number

		PCtoUTT got; // the user's wishes
#if GET_FROM_SOCKET == 0
		ask_user(&got); // ask user for his wishes
#elif
		transfer_uint8_t_to_PCtoUTT(&got, buffer, MAX_BUFF);
#endif

		got.test_number = current_test_number; // set the test number as current test

		UTTtoPC send_end; // the results of the test
		send_end.test_number = got.test_number; // It's the same test number

		Test conclustion; // test; to be written in a file
		conclustion.test_number = current_test_number; // It's the same test number

		ticked_clock_flag = 1; // we are working on a protocol. Turn it on.

		switch(got.protocol) { // need to be got_begin.protocol
			case TIMER_M: // Timer
				send_end.result = do_Timer(&got);
				break;

			case UART_M: // UART
				send_end.result = do_UART(&got);
				break;

			case SPI_M: // SPI
				send_end.result = do_SPI(&got);
				break;

			case I2C_M: // I2C
				send_end.result = do_I2C(&got);
				break;

			case ADC_M: // ADC
				send_end.result = do_ADC(&got);
				break;

			default:
				break;
		}
		ticked_clock_flag = 0; // we are not working on any protocol anymore. Turn it off.

		conclustion.result = send_end.result; // They have the same result
		conclustion.time_took = ticked_clock_counter; // enter how much clock ticks were until now
		ticked_clock_counter = 0; // reset the value of the clock counter to zero

		static RTC_TimeTypeDef sTime; // RTC's time
		static RTC_DateTypeDef sDate; // RTC's Date

		// Get current time and date
		HAL_RTC_GetTime(RtcHandle, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(RtcHandle, &sDate, RTC_FORMAT_BIN);

		sprintf(conclustion.date, "%2.2u-%2.2u-%4.4u - %2.2u:%2.2u:%2.2u", \
				sDate.Date, sDate.Month, sDate.Year + YearStart, \
				sTime.Hours - 1, sTime.Minutes, sTime.Seconds);

		//write to Console the test
		printf("%d (%s for %d clock ticks): %d\r\n", \
				conclustion.test_number, \
				conclustion.date, \
				conclustion.time_took, \
				conclustion.result);
	}
}
