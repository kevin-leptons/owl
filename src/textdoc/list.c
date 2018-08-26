#include <textdoc/list.h>

#include <textdoc/error.h>

static struct td_list_slot *mk_slot_(void) {
        struct td_list_slot *slot;

        slot = malloc(sizeof(*slot));
        if (!slot) {
                td_errno = errno;
                return NULL;
        }
        return slot;
}

void td_list_init(td_list_t *l) {
        l->front = NULL;
        l->back = NULL;
        l->size = 0;
}

void td_list_free(td_list_t *l) {
        struct td_list_slot *slot; 
        struct td_list_slot *tmp;

        for (slot = l->front; slot != NULL;) {
                tmp = slot->next;
                free(slot);
                slot = tmp;
        }

        l->front = NULL;
        l->back = NULL;
        l->size = 0;
}

size_t td_list_size(td_list_t *l) {
        return l->size;
}

void td_list_pushback(td_list_t *l, void *item) {
        struct td_list_slot *slot = mk_slot_();
        slot->item = item;
        slot->prev = NULL;
        slot->next = NULL;
        if (td_errno != TD_ENONE)
                return;

        if (!l->back) {
                l->back = slot;
        } else {
                l->back->next = slot;
                slot->prev = l->back;
                l->back = slot;
        }
        if (!l->front)
                l->front = slot;
        l->size += 1;
}

td_list_slot_t *td_list_begin(td_list_t *l) {
        return l->front;
}

td_list_slot_t *td_list_end(td_list_t *l) {
        return NULL;
}

void *td_list_item(td_list_slot_t *slot) {
        return slot->item;
}

td_list_slot_t *td_list_next(td_list_slot_t *slot) {
        return slot->next;
}
