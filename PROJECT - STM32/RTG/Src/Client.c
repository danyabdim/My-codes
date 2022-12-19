#include "RTG.h"
// Client == Computer

// completes user's desires
void ask_user(PCtoUTT *test) {

	// ask user for number of protocol
	ASK_USER_COM; // prompt of asking for number of protocol
	test->protocol = 0; // set protocol to 0, just in case there will be a garbage value
	scanf("%hhd", &test->protocol); // set protocol as what the user asked
	while(getchar() != '\n'); // clean buffer

	while(!is_protocol_ok(test->protocol)) {
		 // user didn't do what he was asked for - Protocol is not as assign
		printf("Please Try Again!\r\n");
		ASK_USER_COM; // prompt of asking for number of protocol
		scanf("%hhd", &test->protocol); // set protocol as what the user asked
		while(getchar() != '\n'); // clean buffer
	}

	// ask user for number of iterations
	ASK_USER_ITE; // prompt of asking for number of iterations
	test->num_of_iterations = 0; // set num_of_iterations to 0, just in case there will be a garbage value
	scanf("%hhd", &test->num_of_iterations);
	while(getchar() != '\n'); // clean buffer

	while(!(test->num_of_iterations > 0)) {
		// user didn't do what he was asked for - number of iterations is below 0
		printf("Please Try Again!\r\n");
		ASK_USER_ITE; // prompt of asking for number of iterations
		scanf("%hhd", &test->num_of_iterations); // set protocol as what the user asked
		while(getchar() != '\n'); // clean buffer
	}

	// ask user for text
	int i = 0;
	printf("Enter your text (maximum is %d characters): ", MAX_CHAR_STRING - 1);
	char c = getchar(); // get the first char

	while(c != '\n' && i < MAX_CHAR_STRING - 1) { // until we get to enter
		test->text[i] = c; // add the char to the text
		c = getchar(); // get the next char
		i++;
	}

	for (; i < MAX_CHAR_STRING; i++) {
		test->text[i] = END_OF_STRING; // remove garbage
	}

	test->size_text = strlen(test->text); // set the size_text as length of test->text
}

//checks if the protocol of PCtoUTT is OK.
bool is_protocol_ok(uint8_t protocol) {
	return (protocol == TIMER_M) \
			|| (protocol == UART_M) \
			|| (protocol == SPI_M) \
			|| (protocol == I2C_M) \
			|| (protocol == ADC_M);
}
