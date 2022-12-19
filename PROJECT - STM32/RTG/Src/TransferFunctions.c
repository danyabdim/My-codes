#include "RTG.h"

// transfer function: PCtoUTT -> uint8_t[]
void transfer_PCtoUTT_to_uint8_t(uint8_t *res, PCtoUTT test) {
	// set the first four blocks of res to test.test_number
	res[0] = (test.test_number << 24);
	res[1] = (test.test_number << 16);
	res[2] = (test.test_number <<  8);
	res[3] = (test.test_number <<  0);
	res[4] = test.protocol; // set the 5th block of res to test.protocol
	res[5] = test.num_of_iterations; // set the 6th block of res to test.num_of_iterations
	res[6] = test.size_text; // set the 7th block of res to test.size_text

	// set test.size_text blocks from the 8th block of res to the test.text
	int i = 7;
	while(i < test.size_text + 7) {
		res[i] = (char)test.text[i - 7];
		i++;
	}

	// set the rest as '\0'
	for (; i < MAX_CHAR_STRING; i++) {
		res[i] = END_OF_STRING; // remove garbage
	}
}

// transfer function: UTTtoPC -> uint8_t[]
void transfer_UTTtoPC_to_uint8_t(uint8_t *res, UTTtoPC test) {
	// set the first four blocks of res to test.test_number
	res[0] = (test.test_number << 24);
	res[1] = (test.test_number << 16);
	res[2] = (test.test_number <<  8);
	res[3] = (test.test_number <<  0);
	res[4] = test.result; // set the 5th block of res to test.result
}

// transfer function: uint8_t[] -> PCtoUTT
void transfer_uint8_t_to_PCtoUTT(PCtoUTT *res, uint8_t * test, size_t size) {
	int start_from = 0; // block to start from

	if (is_on_UART == 1) {
		start_from = 1;
		// We are ignoring test[0] because the UART makes the last character into the first.
	}

	// set res->test_number from the four blocks of test
	res->test_number =  test[0 + start_from] * pow(2, 24);
	res->test_number += test[1 + start_from] * pow(2, 16);
	res->test_number += test[2 + start_from] * pow(2, 8);
	res->test_number += test[3 + start_from] * pow(2, 0);
	res->protocol = test[4 + start_from]; // set res->protocol from the 5th block of test
	res->num_of_iterations = test[5 + start_from]; // set res->num_of_iterations from the 6th block of tset
	res->size_text = test[6 + start_from]; // set res->size_text from the 7th block of test

	// set test.text from the test.size_text blocks from the 8th block of res
	int i = 7 + start_from;
	while(i < res->size_text + 7 + start_from) {
		res->text[i - (7 + start_from)] = (char)test[i];
		i++;
	}

	// set the rest as '\0'
	for (; i < MAX_CHAR_STRING + 7 + start_from; i++) {
		res->text[i - (7 + start_from)] = END_OF_STRING; // remove garbage
	}
}

// transfer function: uint8_t[] -> UTTtoPC
void transfer_uint8_t_to_UTTtoPC(UTTtoPC *res, uint8_t * test, size_t size) {
	int start_from = 0; // block to start from

	if (is_on_UART == 1) {
		start_from = 1;
		// We are ignoring test[0] because the UART makes the last character into the first.
	}

	// set res->test_number from the four blocks of test
	res->test_number =  test[0 + start_from] * pow(2, 24);
	res->test_number += test[1 + start_from] * pow(2, 16);
	res->test_number += test[2 + start_from] * pow(2, 8);
	res->test_number += test[3 + start_from] * pow(2, 0);
	res->result = test[4 + start_from]; // set res->result from the 6th block of test
}
