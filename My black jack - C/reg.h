#include "LibraryMain.h"

#ifndef REG_H
    #define REG_H

    #define highest_suit_possible 3 // 0b11
    #define highest_rank_possible (15 << 2) //0b111100

    #define BLACK "\033[0;30m" // terminal color = Black
    #define RED "\033[0;31m" // terminal color = Red
    #define GREEN "\033[0;32m" // terminal color = Green
    #define YEllOW "\033[0;33m" // terminal color = Yellow
    #define PURPLE "\033[0;35m" // terminal color = Purple
    #define WHITE "\033[0;37m" // terminal color = White

    #define BLACK_JACK ""BLACK"Black"WHITE" "RED"Jack!"WHITE"\n"

    #define CASH_AND_POT_PRINT do { \
        printf("You have "GREEN"%d$"WHITE".\n", cash); \
        printf("Your pot is: "PURPLE"%d$"WHITE".\n", pot); \
    } while(0);

    #define NOT_UNDERSTAND_PRINT printf("I don't understand that.\n");
    #define FINISH_CASH_PRINT printf("You finished with "GREEN"%d$"WHITE".\n", cash);
    #define HIT_OR_STAND_PRINT printf("Enter Hit ("YEllOW"h"WHITE") or Stand ("YEllOW"s"WHITE"): ");
    #define OUT_OF_CASH_PRINT printf("You're out of cash to bet. Game Over\n");
    #define ASK_ANOTHER_ROUND_PRINT printf( \
    "Do you want to play another round (enter " \
    YEllOW"y"WHITE" for Yes and " \
    YEllOW"n"WHITE" for No)? ");

    #define WIN_EMOJI_PRINT "You Won! \U0001F451\n"
    #define LOSE_EMOJI_PRINT "You LOST! \xE2\x98\xA0\n"

    #define DO_WIN do { \
        cash += pot * 2; \
        pot = 0; \
    } while(0);

    static const char * const suit_names[] = {
        [0] = "Hearts",
        [1] = "Clubs",
        [2] = "Spades",
        [3] = "Diamonds"
    };

    static const char * const rank_names[] = {
        [1] = "Ace",
        [2] = "2",
        [3] = "3",
        [4] = "4",
        [5] = "5",
        [6] = "6",
        [7] = "7",
        [8] = "8",
        [9] = "9",
        [10] = "10",
        [11] = "Jack",
        [12] = "Queen",
        [13] = "king"
    };

    int get_Random(int lower, int upper);
    uint8_t get_rank(uint8_t data);
    uint8_t get_suit(uint8_t data);
#endif