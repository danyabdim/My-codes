#include "RTG.h"

// doing user's desire of ADC (gets test)
uint8_t do_ADC(PCtoUTT *test) {
	user_on_ADC_flag = 1; // we are working on ADC. Turn it on.
	unsigned long bef_num = 0; // the one before
	int it = 0; // number of iteration
	int res = P_SUCCESS; // res; by default - success
	while (it != test->num_of_iterations) {
		// until we don't get to number of iterations that user asked for
		if (adc_flag) //When TIM3 triggers
		{
			if (it != 0) {
				int th_int = HAL_ADC_GetValue(ADC_1); // get current ADC

				if (th_int != bef_num) {
					// check if they differ - if yes -> set res to failure
					res = P_FAILURE;
				}

				bef_num = th_int; // set the before as this
			} else {
				bef_num = HAL_ADC_GetValue(ADC_1); // set now as before
			}

			adc_flag = 0; // set flag to zero
			it++; // we are going to the next iteration
		}
	}
	user_on_ADC_flag = 0; // we are not working on ADC anymore. Turn it off.
	return res;
}
