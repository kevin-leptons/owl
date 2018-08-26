#ifndef TEXTDOC_LIST_H
#define TEXTDOC_LIST_H

#include <stdlib.h>

typedef struct td_list_slot td_list_slot_t;

struct td_list_slot {
    td_list_slot_t *prev;
    td_list_slot_t *next;
    void *item;
};

typedef struct {
    size_t size;
    struct td_list_slot *front;
    struct td_list_slot *back;
} td_list_t;

void td_list_init(td_list_t *l);
void td_list_free(td_list_t *l);
size_t td_list_size(td_list_t *l);
void td_list_pushback(td_list_t *l, void *item);
td_list_slot_t *td_list_begin(td_list_t *l);
td_list_slot_t *td_list_end(td_list_t *l);
void *td_list_item(td_list_slot_t *slot);
td_list_slot_t *td_list_next(td_list_slot_t *slot);

#endif
