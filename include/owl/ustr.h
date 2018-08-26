#ifndef TD_USTR_H
#define TD_USTR_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct {
    size_t cap;             // read-only
    size_t size;            // read-only
    uint32_t *slots;        // read-only
} td_ustr_t;

void td_ustr_init(td_ustr_t *dst, size_t cap);
void td_ustr_init_from(td_ustr_t *dst, td_ustr_t *src);
void td_ustr_init_seq(td_ustr_t *dst, const uint32_t *src, size_t size);
void td_ustr_init_seqc(td_ustr_t *dst, const char *src, size_t size);
void td_ustr_init_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size);
void td_ustr_free(td_ustr_t *dst);

void td_ustr_swap(td_ustr_t *dst, td_ustr_t *src);
void td_ustr_move(td_ustr_t *dst,td_ustr_t *src);

void td_ustr_copy(td_ustr_t *dst, td_ustr_t *src);
void td_ustr_copy_seq(td_ustr_t *dst, const uint32_t *src, size_t size);
void td_ustr_copy_seqc(td_ustr_t *dst, const char *src, size_t size);
void td_ustr_copy_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size);

void td_ustr_ins(td_ustr_t *dst, const td_ustr_t *src, size_t index);
void td_ustr_ins_seq(
    td_ustr_t *dst,
    const uint32_t *src,
    size_t index,
    size_t size
);
void td_ustr_ins_seqc(
    td_ustr_t *dst,
    const char *src,
    size_t index,
    size_t size
);
void td_ustr_ins_seqwc(
    td_ustr_t *dst,
    const wchar_t *src,
    size_t index,
    size_t size
);

void td_ustr_pub(td_ustr_t *dst, uint32_t code);
void td_ustr_pubc(td_ustr_t *dst, char code);
void td_ustr_pubwc(td_ustr_t *dst, wchar_t code);

void td_ustr_cat(td_ustr_t *dst, td_ustr_t *src);
void td_ustr_cat_seq(td_ustr_t *dst, const uint32_t *src, size_t size);
void td_ustr_cat_seqc(td_ustr_t *dst, const char *src, size_t size);
void td_ustr_cat_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size);

void td_ustr_sub(
    td_ustr_t *dst,
    const td_ustr_t *src,
    size_t begin,
    size_t size
);
void td_ustr_erase(td_ustr_t *dst, size_t begin, size_t size);
void td_ustr_clean(td_ustr_t *dst);
void td_ustr_lower(td_ustr_t *dst);
void td_ustr_upper(td_ustr_t *dst);

uint32_t td_ustr_get(td_ustr_t *dst, size_t index);
void td_ustr_set(td_ustr_t *dst, size_t index, uint32_t code);
void td_ustr_setc(td_ustr_t *dst, size_t index, char code);
void td_ustr_setwc(td_ustr_t *dst, size_t index, wchar_t code);

#endif
