#ifndef TD_SYMBOL_H
#define TD_SYMBOL_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

struct td_symbol_range {
    uint32_t begin;
    uint32_t end;
};

bool td_symbol_match(
    uint32_t symbol,
    struct td_symbol_range *ranges, 
    size_t size
);

#endif
