/*
	Vector
*/

#ifndef TD_VECTOR_H
#define TD_VECTOR_H

#include <stdlib.h>

typedef struct {
	size_t cap;
	size_t size;
	size_t slot_size;
	void *slots;
} td_vector_t;

void td_vector_init(td_vector_t *v, size_t cap, size_t slot_size);
void td_vector_free(td_vector_t *v);
void td_vector_pushback(td_vector_t *v, void *item);
void td_vector_clean(td_vector_t *v);
void td_vector_copy(td_vector_t *dest, td_vector_t *src);

#endif
