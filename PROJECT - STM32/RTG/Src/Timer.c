#include "RTG.h"

// doing user's desire of timer (gets test)
uint8_t do_Timer(PCtoUTT *test) {
	user_on_time_flag = 1; // we are working on Timer. Turn it on.
	int it = 0; // number of iteration
	int time_passed = 0; //time passed used as checking time

	while (it != test->num_of_iterations) { // until we don't get to number of iterations that user asked for
		if (time_flag) //When TIM3 triggers
		{
			time_passed++; // increase the time_passed by 1
			time_flag = 0; // set flag to zero
			it++; // we are going to the next iteration
		}
	}

	user_on_time_flag = 0; // we are not working on Timer anymore. Turn it off.

	if(ticked_clock_counter != time_passed) {
		// if the time of TIME is different from the time of time.h -> send failure
		return (uint8_t)P_FAILURE;
	}
	// send success (because the time of TIME is as same as the time of time.h)
	return (uint8_t)P_SUCCESS;
}
