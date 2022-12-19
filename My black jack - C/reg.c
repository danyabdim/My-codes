#include "reg.h"

int get_Random(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

uint8_t get_rank(uint8_t data) {
    return ((data) & (highest_rank_possible)) >> 2;
}

uint8_t get_suit(uint8_t data) {
    return (data) & (highest_suit_possible);
}
