#include "Card.h"

void add_card(Card_t** head_ref, int new_data) {  
    //create a new node
    Card_t *newNode = NULL;
    newNode = malloc(sizeof(*newNode));
    
    if (newNode == NULL) {
        printf("Couldn't allocate memory.\n");
        return;
    }

    newNode->data = new_data;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if (*head_ref == NULL) {
         *head_ref = newNode;
    } else {
        //Otherwise, find the last node and add the newNode
        Card_t *lastNode = *head_ref;

        //last node's next address will be NULL.
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
}

Card_t* remove_card(Card_t* head, int index) {
    Card_t *tmp;

    if (!head) {
	  return NULL;
    }

    if (index == 0) {
        tmp = head;
        head=head->next;
        free(tmp);
        return head;
    }

    head->next = remove_card(head->next, index - 1);
    return head;
}

bool is_there_card(Card_t *head, int data) {
    Card_t *this_Node = head;

    while (this_Node != NULL) {
        if (this_Node->data == data) {
            return true;
        }

        this_Node = this_Node->next;
    }

    return false;
}

void show(Card_t *head, int count, bool unshow_deal) {
    if (!head) {
        return;
    }

    uint8_t rank = get_rank(head->data);
    uint8_t suit = get_suit(head->data);

    if (unshow_deal == true && count != 1) {
        printf("??????");
    } else {
        if (strcmp(suit_names[suit], "Clubs") == 0 || strcmp(suit_names[suit], "Spades") == 0) {
            printf(BLACK); // set colors in terminal
        } else {
            printf(RED); // set colors in terminal
        }
        printf("%s of %s", suit_names[suit], rank_names[rank]);
        printf(WHITE); // set colors in terminal
    }

    if (head->next != NULL) {
        printf(", ");
    }

    show(head->next, count + 1, unshow_deal);
}