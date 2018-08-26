/*
NAME

    uss - unicode symbol stream for file.
*/

#include <stdio.h>
#include <inttypes.h>

#ifndef TD_USS_H
#define TD_USS_H

typedef struct {
    FILE *fs;
} td_uss_t;

void td_uss_init(td_uss_t *s, const char *file);
void td_uss_free(td_uss_t *s);
uint32_t td_uss_getc(td_uss_t *s);
void td_uss_write(td_uss_t *s, uint32_t symbol);

#endif

