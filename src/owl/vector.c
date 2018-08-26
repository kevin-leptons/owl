#include <owl/vector.h>

#include <owl/error.h>

void td_vector_init(td_vector_t *v, size_t cap, size_t slot_size) {
    void *slots = malloc(slot_size * cap);
    if (!slots) {
        td_errno = errno;
        return;
    }
    v->slots = slots;
    v->cap = cap;
    v->size = 0;
    v->slot_size = slot_size;
}

void td_vector_free(td_vector_t *v) {

}

void td_vector_pushback(td_vector_t *v, void *item) {

}

void td_vector_clean(td_vector_t *v) {

}

void td_vector_copy(td_vector_t *dest, td_vector_t *src) {

}
