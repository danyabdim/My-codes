#include "LibraryMain.h"
#include "reg.h"

#ifndef CARD_H
    #define CARD_H

    typedef struct Card {
        uint8_t data;
        struct Card * next;
    } Card_t;

    void add_card(Card_t** head_ref, int new_data);
    Card_t* remove_card(Card_t* head, int index);
    bool is_there_card(Card_t *head, int data);
    void show(Card_t *head, int count, bool unshow_deal);
#endif