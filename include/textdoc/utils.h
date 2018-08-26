/*
NAME

        utils - utilities functions
*/

#ifndef TD_UTILS_H
#define TD_UTILS_H

#include <stdlib.h>
#include <inttypes.h>

void td_swap_uint32(uint32_t *lhs, uint32_t *rhs);
void td_swap_size(size_t *lhs, size_t *rhs);
void td_swap_pointer(void **lhs, void **rhs);

#endif
