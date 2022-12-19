#include "CardList.h"

void init_cardlist(CardList_t *cardlist) {
    cardlist->head = NULL;
    cardlist->len = 0;
}

void fill_deck(CardList_t *cardlist) {
    for (int i = 1; i <= 52; i++) {
        int data;

        if (i % 13 == 0) {
            data = (i - 1) / 13; // suit
            data += (13 << 2); // rank
        } else {
            data = (i / 13); // suit
            data += ((i % 13) << 2); // rank
        }

        add_card(&(cardlist->head), data);
        cardlist->len++;
    }
}

void clear_cardlist(CardList_t *cardlist) {
    while (cardlist->head != NULL) {
        cardlist->head = remove_card(cardlist->head, 0);
    }
}

void card_remove_at(CardList_t *cardlist, int index) {
    remove_card(cardlist->head, index);
    cardlist->len--;
}

int card_draw(CardList_t *cardlist) {
    int choosen_data = get_Random(4, 55); // 4 - the smallest; 55 - the biggest
    while (is_there_card(cardlist->head, choosen_data) == false) {
        choosen_data = get_Random(4, 55); // 4 - the smallest; 55 - the biggest
    }
    return choosen_data;
}

void card_push(CardList_t *cardlist, int data) {
    add_card(&(cardlist->head), data);
    cardlist->len++;
}

int get_sum(CardList_t *cardlist, bool to_not_show) {
    Card_t *p = cardlist->head;
    int count = 1;
    int sum = 0;
    int count_a = 0;
    while (p != NULL) {   
        int rank = get_rank(p->data);
        
        if (rank > 10) {
            sum += 10;
        } else {
            sum += rank;
        }

        if (rank == 1) {
            sum += 10;
            count_a++;
        }

        p = p->next;

        if (to_not_show && count != 1) {
            if (rank > 10) {
                sum -= 10;
            } else {
                sum -= rank;
            }

            if (rank == 1) {
                sum -= 10;
                count_a--;
            }
        }
        count++;
    }

    for (int k = 0; k < count_a; k++) {
        if (sum > 21) {
            sum -= 10;
        }
    }
    return sum;
}

void print_cards(CardList_t *cardlist, bool is_dealer, bool unshow_deal) {
    if (is_dealer == true) {
        printf("The dealer have: ");
    } else {
        printf("The player have: ");
    }

    show(cardlist->head, 1, unshow_deal);
    int sum = get_sum(cardlist, unshow_deal);
    printf(" (%d)\n", sum);
}

void init_and_fill_cardlists(CardList_t *deck, CardList_t *user_hand, CardList_t *dealer_hand) {
    init_cardlist(deck);
    fill_deck(deck);
    init_cardlist(user_hand);
    init_cardlist(dealer_hand);
}

void card_draw_and_replace(CardList_t *deck, CardList_t *hand) {
    int cho_rand = card_draw(deck);
    card_push(hand, cho_rand);
    card_remove_at(deck, cho_rand);
}

void clear_cardlists(CardList_t *deck, CardList_t *user_hand, CardList_t *dealer_hand) {
    clear_cardlist(deck);
    clear_cardlist(user_hand);
    clear_cardlist(dealer_hand);
}