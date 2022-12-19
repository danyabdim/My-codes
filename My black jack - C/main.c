#include "LibraryMain.h"
#include "Card.h"
#include "CardList.h"
#include "reg.h"

int main() {
    srand(time(NULL));
    int pot = 0, cash = 1000;
    printf("Welcome to "BLACK_JACK);

    // Create deck and fill cards
    CardList_t deck, user_hand, dealer_hand;
    init_and_fill_cardlists(&deck, &user_hand, &dealer_hand);
    //print_cards(&deck, false, false);

    CASH_AND_POT_PRINT;
    
    while(1) {
        // Ask the Player for bet
        //print_cards(&deck, false, false);
        int bet = 0, user_sum = 0, dealer_sum = 0;
        
        while(1) {
            printf("Enter your bet: ");
            scanf("%d", &bet);
            
            while (getchar() != '\n'); // clear buffer

            if ((pot > 0 && bet == 0) || (bet % 10 == 0 && bet <= cash && bet > 0)) {
                break;
            }

            printf("Please try again.\n");
        }

        pot += bet;
        cash -= bet;

        // Give cards to Player and Dealer (2 each)
        card_draw_and_replace(&deck, &user_hand); // First card to the User
        card_draw_and_replace(&deck, &dealer_hand); // First card to the Dealer
        card_draw_and_replace(&deck, &user_hand); // Second card to the User
        card_draw_and_replace(&deck, &dealer_hand); // Second card to the Dealer

        // Print Player's & dealer's hand
        print_cards(&user_hand, false, false);
        print_cards(&dealer_hand, true, true);
        //print_cards(&dealer_hand, true, false);

        user_sum = get_sum(&user_hand, false);
        dealer_sum = get_sum(&dealer_hand, false);
        //printf("%d\n", user_sum);
        //printf("%d\n", dealer_sum);

        // Ask the Player about additional cards
        int err_bust = 0;
        
        while(1) {
            if (user_sum == 21) {
                printf(BLACK_JACK);
                break;
            }

            if (user_sum > 21) {
                printf("Bust! "LOSE_EMOJI_PRINT);
                pot = 0;
                err_bust = 1;
                break;
            }

            char c;
            int err_no_what_expected = 0;

            HIT_OR_STAND_PRINT;
            c = getchar();
            while (getchar() != '\n') { // clear buffer
                err_no_what_expected = 1;
            }

            if (err_no_what_expected == 1) {
                NOT_UNDERSTAND_PRINT;
            } else {
                switch(c) {
                    case 'h':
                    case 'H': // The Player choosed Hit
                        card_draw_and_replace(&deck, &user_hand);
                        user_sum = get_sum(&user_hand, false);
                        print_cards(&user_hand, false, false);
                        break;
                    case 's':
                    case 'S': // The Player choosed Stand
                        break;
                    default: // The Player didn't give 'h' or 's' followed by Enter key.
                        NOT_UNDERSTAND_PRINT;
                        break;
                }
            }

            if ((c == 's' || c == 'S') && (err_no_what_expected != 1)) {
                break;
            }
        }

        if (err_bust != 1) {
            // Ask The Dealer about additional cards
            while (1) {
                if (dealer_sum >= 17 || dealer_sum > user_sum) {
                    break;
                }
                
                printf("The dealer took a card.\n");
                card_draw_and_replace(&deck, &dealer_hand);
                dealer_sum = get_sum(&dealer_hand, false);
                //print_cards(&dealer_hand, true, true);
            }

            // Check win/lost condition and print results
            if (dealer_sum > 21) {
                print_cards(&dealer_hand, true, false);
                printf("Dealer's Bust! "WIN_EMOJI_PRINT);
                DO_WIN;
            } else {
                if (dealer_sum == user_sum) {
                    print_cards(&dealer_hand, true, false);
                    printf("Tie!\n");
                } else if (dealer_sum < user_sum) {
                    print_cards(&dealer_hand, true, false);
                    printf(WIN_EMOJI_PRINT);
                    DO_WIN;
                } else {
                    print_cards(&dealer_hand, true, false);
                    printf("Dealer Won! "LOSE_EMOJI_PRINT);
                    pot = 0;
                }
            }
        }

        //printf("%d\n", user_sum);
        //printf("%d\n", dealer_sum);
        // Reset cards & Ask the Player if he wants to play again
        clear_cardlists(&deck, &user_hand, &dealer_hand);

        if (pot == 0 && cash < 10) {
            OUT_OF_CASH_PRINT;
            break;
        }

        int err_more_than_one = 0;
        char c_end = '\0';
        while(1) {
            err_more_than_one = 0;
            CASH_AND_POT_PRINT;

            if (pot != 0) {
                init_and_fill_cardlists(&deck, &user_hand, &dealer_hand);
                break;
            }

            ASK_ANOTHER_ROUND_PRINT;
            c_end = getchar();
            while (getchar() != '\n') { // clear buffer
                err_more_than_one = 1;
            }

            if (err_more_than_one == 1) {
                NOT_UNDERSTAND_PRINT;
            } else {
                switch(c_end) {
                    case 'y':
                    case 'Y': // The Player choosed Yes
                        init_and_fill_cardlists(&deck, &user_hand, &dealer_hand);
                        break;
                    case 'n':
                    case 'N': // The Player choosed No
                        break;
                    default: // The Player didn't give 'y' or 'n' followed by Enter key.
                        NOT_UNDERSTAND_PRINT;
                        break;
                }
            }

            if ((c_end == 'n' || c_end == 'N' || c_end == 'y' || c_end == 'Y') && (err_more_than_one != 1)) {
                break;
            }
        }

        if ((c_end == 'n' || c_end == 'N') && (err_more_than_one != 1)) {
            FINISH_CASH_PRINT;
            break;
        }
    }
    return 0;
}