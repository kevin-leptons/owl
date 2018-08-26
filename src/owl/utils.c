#include <owl/utils.h>

void td_swap_uint32(uint32_t *lhs, uint32_t *rhs) {
    uint32_t tmp;

    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void td_swap_size(size_t *lhs, size_t *rhs) {
    size_t tmp;

    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void td_swap_pointer(void **lhs, void **rhs) {
    void *tmp;

    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}
