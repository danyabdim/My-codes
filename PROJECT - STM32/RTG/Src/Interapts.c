#include "RTG.h"

// ADC interrupt Callback (convert data finish)
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	adc_flag = 1;
}

// Timer interrupt Callback is triggered every 1 second
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (ticked_clock_flag == 1) { // We are working on protocol.
		ticked_clock_counter++;
	}
	if (user_on_ADC_flag == 1) { // We are on ADC
		HAL_ADC_Start_IT(ADC_1);
	}
	if (user_on_time_flag == 1) { // We are on time
		time_flag = 1;
	}
}
