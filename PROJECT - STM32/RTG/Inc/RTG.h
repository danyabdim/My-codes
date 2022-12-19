#ifndef INC_RTG_H_
#define INC_RTG_H_
#include "main.h"
#include "stm32f7xx_hal.h"

#include "lwip.h"
#include "fatfs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

extern UART_HandleTypeDef huart3;		//Change to match your UART number
extern UART_HandleTypeDef huart5;		//Change to match your UART number
extern UART_HandleTypeDef huart6;		//Change to match your UART number
extern TIM_HandleTypeDef htim3;			//Change to match your TIME number
extern TIM_HandleTypeDef htim4;			//Change to match your TIME number
extern ADC_HandleTypeDef hadc1;			//Change to match your ADC  number
extern SPI_HandleTypeDef hspi2;			//Change to match your SPI  number
extern SPI_HandleTypeDef hspi3;			//Change to match your SPI  number
extern I2C_HandleTypeDef hi2c1;			//Change to match your I2C  number
extern I2C_HandleTypeDef hi2c2;			//Change to match your I2C  number
extern RTC_HandleTypeDef hrtc;			//Change to match your I2C  number

#define END_OF_STRING 0 				// '\0'
#define BACKSPACE 8 					// char that is a carriage backspace
#define LINE_FEED 10 					// char that is a line feed
#define CARRIAGE_RETURN 13 				// char that is a carriage return

#define UART_DEBUG &huart3				//Change to match your UART number
#define UART_5 &huart5					//Change to match your UART number
#define UART_6 &huart6					//Change to match your UART number
#define ADC_1 &hadc1					//Change to match your ADC  number
#define TIM_3 &htim3					//Change to match your TIME number
#define SPI_2 &hspi2					//Change to match your SPI  number
#define SPI_3 &hspi3					//Change to match your SPI  number
#define I2C_1 &hi2c1					//Change to match your I2C  number
#define I2C_2 &hi2c2					//Change to match your TRC  number
#define RtcHandle &hrtc

#define HAL_DELAY_TIME 1000				//Delay Time for HAL_Delay
#define HAL_DELAY_Transmit_TIME 500		//Delay Time for Delay in Transmit
#define MAX_CHAR_STRING 101				//The maximum length of string you can send; the last string is reserved for '\0'
#define MAX_BUFF MAX_CHAR_STRING + 7	//maximum of buff you can send/receive

#define TIMER_M 1 						//Number of Timer Protocol
#define UART_M 2						//Number of UART  Protocol
#define SPI_M 4							//Number of SPI   Protocol
#define I2C_M 8							//Number of I2C   Protocol
#define ADC_M 16						//Number of ADC   Protocol

#define P_FAILURE 0xff 					// Result of Failure
#define P_SUCCESS 1 					// Result of Success

#define I2C_SLAVE_ADRESS 44 			// I2C Slave's address
#define SERVER_PORT 7 					// Server's port

#define BLACK "\033[0;30m" 				// terminal color = Black
#define RED "\033[0;31m" 				// terminal color = Red
#define GREEN "\033[1;32m" 				// terminal color = Green
#define BLUE "\033[1;34m" 				// terminal color = Blue
#define PURPLE "\033[1;35m" 			// terminal color = Purple

#define GET_FROM_SOCKET 0 				// set 1 as get from socket and 0 as get from console

#define ASK_USER_COM \
	do{ \
		printf("Which Number of protocol do you want to send to?\r\n"); \
		printf(RED"%d"BLACK" - "GREEN"Timer; " \
		RED"%d"BLACK" - "GREEN"UART"BLACK"; " \
		RED"%d"BLACK" - "GREEN"SPI"BLACK"; " \
		RED"%d"BLACK" - "GREEN"I2C"BLACK"; " \
		RED"%d"BLACK" - "GREEN"ADC"BLACK"\r\n", \
		TIMER_M, UART_M, SPI_M, I2C_M, ADC_M); \
		printf(BLUE"Answer: "BLACK); \
	} \
	while(0); // prompt of asking for number of protocol

#define ASK_USER_ITE \
	do{ \
		printf("How many iterations do you want to run?\r\n"); \
		printf(BLUE"Answer: "BLACK); \
	} \
	while(0); // prompt of asking for number of iterations

typedef struct PCtoUTT {
	int test_number;					//number of test
	uint8_t protocol;					//protocol to use; 1 - Timer; 2 - UART; 4 - SPI; 8 - I2C; 16 - ADC
	uint8_t num_of_iterations;			//number of iterations to do
	uint8_t size_text;					//size of text
	char text[MAX_CHAR_STRING];			//text
} PCtoUTT;								//What PC sends to UTT

typedef struct UTTtoPC {
	int test_number;					//number of test
	uint8_t result;						//result of test
} UTTtoPC;								//What UTT sends to PC

typedef struct Test {
	int test_number;					//number of test
	char * date;						//date the test was taken
	uint8_t time_took;					//time took for the test
	uint8_t result;						//result of test
} Test;									//What Enters to the file

//main function
void rtg_main();

// completes user's desires
void ask_user(PCtoUTT *res);

//checks if the protocol of PCtoUTT is OK.
bool is_protocol_ok(uint8_t protocol);

// doing user's desire of timer (gets test)
uint8_t do_Timer(PCtoUTT *test);

// doing user's desire of UART (gets test)
uint8_t do_UART(PCtoUTT *test);

// doing user's desire of SPI (gets test)
uint8_t do_SPI(PCtoUTT *test);

// doing user's desire of I2C (gets test)
uint8_t do_I2C(PCtoUTT *test);

// doing user's desire of ADC (gets test)
uint8_t do_ADC(PCtoUTT *test);

// initializer of UDP Server
void udpServer_init(void);

// transfer function: PCtoUTT -> uint8_t[]
void transfer_PCtoUTT_to_uint8_t(uint8_t *res, PCtoUTT test);

// transfer function: UTTtoPC -> uint8_t[]
void transfer_UTTtoPC_to_uint8_t(uint8_t *res, UTTtoPC test);

// transfer function: uint8_t[] -> PCtoUTT
void transfer_uint8_t_to_PCtoUTT(PCtoUTT *res, uint8_t * test, size_t size);

// transfer function: uint8_t[] -> UTTtoPC
void transfer_uint8_t_to_UTTtoPC(UTTtoPC *res, uint8_t * test, size_t size);

extern uint8_t time_flag;							//Flag when TIME encounters an interrupt event
extern uint8_t user_on_time_flag;					//Flag when we are on the time or ADC test
extern uint8_t user_on_ADC_flag;					//Flag when we are on the time or ADC test
extern uint8_t adc_flag;							//Flag when ADC  encounters an interrupt event
extern uint8_t ticked_clock_counter;				//Counter ticking clock when we are working on protocol.
extern uint8_t ticked_clock_flag;					//Flag when we are working on protocol.
extern struct netif gnetif;							//Package
extern uint16_t YearStart;							//Year start to adding to RTC's year
extern uint8_t is_on_UART;							//Flag when working on UART

#if GET_FROM_SOCKET == 1
	extern uint8_t buffer[MAX_BUFF];
#endif

#endif /* INC_RTG_H_ */
