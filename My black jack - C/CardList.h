#include "LibraryMain.h"
#include "Card.h"
#include "reg.h"

#ifndef CARDLIST_H
    #define CARDLIST_H

    typedef struct CardList {
        Card_t *head;
        size_t len;
    } CardList_t;

    void init_cardlist(CardList_t *cardlist);
    void fill_deck(CardList_t *cardlist);
    void clear_cardlist(CardList_t *cardlist);
    void card_remove_at(CardList_t *cardlist, int index);
    int card_draw(CardList_t *cardlist);
    void card_push(CardList_t *cardlist, int data);
    int get_sum(CardList_t *cardlist, bool to_not_show);
    void print_cards(CardList_t *cardlist, bool is_dealer, bool unshow_deal);
    void init_and_fill_cardlists(CardList_t *deck, CardList_t *user_hand, CardList_t *dealer_hand);
    void card_draw_and_replace(CardList_t *deck, CardList_t *hand);
    void clear_cardlists(CardList_t *deck, CardList_t *user_hand, CardList_t *dealer_hand);
#endif