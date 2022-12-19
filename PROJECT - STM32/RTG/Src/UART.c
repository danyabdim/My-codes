#include "RTG.h"

// doing user's desire of UART (gets test)
uint8_t do_UART(PCtoUTT *test) {

	is_on_UART = 1; // We are working on UART. Turn it on.
	uint8_t buff_send[MAX_BUFF]; // transmit buff
	uint8_t buff_get[MAX_BUFF]; // receive buff

	 // transmit the PCtoUTT you got into the buff send
	transfer_PCtoUTT_to_uint8_t(buff_send, *test);

	for (int count = 0; count < test->num_of_iterations; count++) {
		//We are running this test the number of iterations we were given.

		PCtoUTT got_inside;

		// first transmits to second & second receives from first
		HAL_UART_Receive_IT(UART_6, &buff_get, MAX_BUFF);
		HAL_UART_Transmit(UART_5, &buff_send, MAX_BUFF, HAL_DELAY_Transmit_TIME);
		HAL_Delay(HAL_DELAY_TIME); // delay for HAL_DELAY_TIME

		// transfer what you got into got_inside and transfer it into buff_send
		transfer_uint8_t_to_PCtoUTT(&got_inside, buff_get, MAX_BUFF);
		transfer_PCtoUTT_to_uint8_t(buff_send, got_inside);

		// second transmits to first & first receives from second
		HAL_UART_Receive_IT(UART_5, &buff_get, MAX_BUFF);
		HAL_UART_Transmit(UART_6, &buff_send, MAX_BUFF, HAL_DELAY_Transmit_TIME);
		HAL_Delay(HAL_DELAY_TIME); // delay for HAL_DELAY_TIME

		// transfer what you got into got_inside
		transfer_uint8_t_to_PCtoUTT(&got_inside, buff_get, MAX_BUFF);

		if (strcmp(test->text, got_inside.text) != 0) {
			is_on_UART = 0; // We are not working on UART anymore. Turn it off.
			//if you got different text in both of them -> send failure
			return (uint8_t)P_FAILURE;
		}
	}
	is_on_UART = 0; // We are not working on UART anymore. Turn it off.
	//everything got smooth -> send success
	return (uint8_t)P_SUCCESS;
}
