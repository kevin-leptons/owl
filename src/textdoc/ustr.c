#include <textdoc/ustr.h>

#include <string.h>

#include <textdoc/error.h>
#include <textdoc/utils.h>

#define UCODE_SIZE sizeof(uint32_t)

void td_ustr_init(td_ustr_t *dst, size_t cap)
{
        if (cap > 0) {
                dst->slots = malloc(UCODE_SIZE * (cap + 1));
                if (!dst->slots) {
                        td_errno = errno;
                        return;
                }
        } else {
                dst->slots = NULL;
        }
        dst->cap = cap;
        dst->size = 0;
}

void td_ustr_init_from(td_ustr_t *dst, td_ustr_t *src)
{
        td_ustr_init(dst, 0);
        td_ustr_copy(dst, src);
}

void td_ustr_init_seq(td_ustr_t *dst, const uint32_t *src, size_t size)
{
        td_ustr_init(dst, 0);
        td_ustr_copy_seq(dst, src, size);
}

void td_ustr_init_seqc(td_ustr_t *dst, const char *src, size_t size)
{
        td_ustr_init(dst, 0);
        td_ustr_copy_seqc(dst, src, size);
}

void td_ustr_init_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size)
{
        td_ustr_init(dst, 0);
        td_ustr_copy_seqwc(dst, src, size);
}

void td_ustr_free(td_ustr_t *s)
{
        if (s->slots) {
                free(s->slots);
                s->slots = NULL;
        }
        s->cap = 0;
        s->size = 0;
}

void td_ustr_swap(td_ustr_t *dst, td_ustr_t *src)
{
        td_swap_size(&dst->cap, &src->cap);
        td_swap_size(&dst->size, &src->size);
        td_swap_pointer((void *) &dst->slots, (void *) &src->slots);
}

void td_ustr_move(td_ustr_t *dst,td_ustr_t *src)
{
        td_ustr_swap(dst, src);
        td_ustr_free(src);
}

void td_ustr_copy(td_ustr_t *dst, td_ustr_t *src)
{
        if (dst->cap < src->size) {
                td_ustr_t tmp;

                td_ustr_init(&tmp, src->size + 1);
                td_ustr_copy(&tmp, src);
                td_ustr_swap(&tmp, dst);
                td_ustr_free(&tmp);
        } else {
                memcpy(dst->slots, src->slots, sizeof(uint32_t) * src->size);
                dst->slots[src->size] = 0;
                dst->size = src->size;
        }
}

void td_ustr_copy_seq(td_ustr_t *dst, const uint32_t *src, size_t size)
{
        if (dst->cap < size) {
                td_ustr_free(dst);
                td_ustr_init(dst, size);
        }
        memcpy(dst->slots, src, UCODE_SIZE * size);
        dst->size = size;
}

void td_ustr_copy_seqc(td_ustr_t *dst,const char *src, size_t size)
{
        if (dst->cap < size) {
                td_ustr_free(dst);
                td_ustr_init(dst, size);
        }

        for (size_t i = 0; i < size; ++i)
                dst->slots[i] = src[i];
        dst->slots[size] = 0;
        dst->size = size;
}

void td_ustr_copy_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size)
{
        if (dst->cap < size) {
                td_ustr_free(dst);
                td_ustr_init(dst, size);
        }
        for (size_t i = 0; i < size; ++i)
                dst->slots[i] = src[i];
        dst->size = size;
}

void td_ustr_ins(td_ustr_t *dst, const td_ustr_t *src, size_t index)
{
        if (index > dst->size) {
                td_errno = TD_EINDEX;
                return;
        }

        if (dst->cap < dst->size + src->size) {
                td_ustr_t tmp;

                td_ustr_init(&tmp, 0);
                td_ustr_copy(&tmp, dst);
                td_ustr_swap(&tmp, dst);
                td_ustr_free(&tmp);
        }
        memcpy(&dst->slots[index + 1], src->slots, UCODE_SIZE * src->size);
        dst->size += src->size;
        dst->slots[dst->size] = 0;
}

void td_ustr_ins_seq(
        td_ustr_t *dst,
        const uint32_t *src,
        size_t index,
        size_t size
)
{
        if (index > dst->size) {
                td_errno = TD_EINDEX;
                return;
        }

        td_ustr_t tmp;

        td_ustr_init(&tmp, dst->size + size);
        if (td_errno)
                return;

        if (index > 0)
                memcpy(tmp.slots, dst->slots, index * UCODE_SIZE);
        memcpy(&tmp.slots[index], src, UCODE_SIZE * size);
        if (index < dst->size) {
                memcpy(&tmp.slots[index + size], &dst->slots[index],
                        (dst->size - index + 1) * UCODE_SIZE);
        }
        tmp.size = dst->size + size;
        tmp.slots[tmp.size] = 0;

        td_ustr_swap(&tmp, dst);
        td_ustr_free(&tmp);
}

void td_ustr_ins_seqc(
        td_ustr_t *dst,
        const char *src,
        size_t index,
        size_t size
)
{
        if (index > dst->size) {
                td_errno = TD_EINDEX;
                return;
        }
        if (size == 0)
                return;

        td_ustr_t tmp;
        td_ustr_init(&tmp, dst->size + size);
        if (td_errno)
                return;

        if (index > 0)
                memcpy(tmp.slots, dst->slots, index * UCODE_SIZE);
        for (size_t i = 0; i < size; ++i)
                tmp.slots[index + i] = src[i];
        if (index < dst->size) {
                memcpy(&tmp.slots[index + size], &dst->slots[index],
                                (dst->size - index) * UCODE_SIZE);
        }
        tmp.size = dst->size + size;
        tmp.slots[tmp.size] = 0;

        td_ustr_swap(&tmp, dst);
        td_ustr_free(&tmp);
}

void td_ustr_ins_seqwc(
        td_ustr_t *dst,
        const wchar_t *src,
        size_t index,
        size_t size
)
{
        if (index > dst->size) {
                td_errno = TD_EINDEX;
                return;
        }

        td_ustr_t tmp;
        td_ustr_init(&tmp, dst->size + size);
        if (td_errno)
                return;

        if (index > 0) {
                memcpy(tmp.slots, dst->slots,
                                (index - 1) * UCODE_SIZE);
        }
        for (size_t i = 0; i < size; ++i)
                tmp.slots[index + i] = src[i];
        if (index < size) {
                memcpy(&tmp.slots[index + size], &dst->slots[index],
                                (size - index + 1) * UCODE_SIZE);
        }
        tmp.size = dst->size + size;
        tmp.slots[tmp.size] = 0;

        td_ustr_swap(&tmp, dst);
        td_ustr_free(&tmp);
}

void td_ustr_pub(td_ustr_t *dst, uint32_t code)
{
        if (dst->cap < dst->size + 1) {
                td_ustr_t tmp;
                td_ustr_init(&tmp, dst->cap == 0 ? 16 : 2 * dst->cap);
                memcpy(tmp.slots, dst->slots, UCODE_SIZE * dst->size);
                tmp.slots[dst->size] = code;
                tmp.size = dst->size + 1;
                tmp.slots[tmp.size] = 0;

                td_ustr_swap(&tmp, dst);
                td_ustr_free(&tmp);
        } else {
                dst->slots[dst->size] = code;
                dst->size++;
                dst->slots[dst->size] = 0;
        }
}

void td_ustr_pubc(td_ustr_t *dst, char code)
{
        uint32_t ucode = code;
        td_ustr_pub(dst, ucode);
}

void td_ustr_pubwc(td_ustr_t *dst, wchar_t code)
{
        uint32_t ucode = code;
        td_ustr_pub(dst, ucode);
}

void td_ustr_cat(td_ustr_t *dst, td_ustr_t *src)
{
        if (dst->cap < dst->size + src->size) {
                td_ustr_t tmp;
                td_ustr_init(&tmp, dst->size + src->size);
                if (td_errno)
                        return;

                memcpy(tmp.slots, dst->slots, dst->size * UCODE_SIZE);
                memcpy(&tmp.slots[dst->size], src->slots,
                        src->size * UCODE_SIZE);
                tmp.size = dst->size + src->size;
                tmp.slots[tmp.size] = 0;

                td_ustr_swap(&tmp, dst);
                td_ustr_free(&tmp);
        } else {
                memcpy(&dst->slots[dst->size], src->slots,
                        src->size * UCODE_SIZE);
                dst->size += src->size;
                dst->slots[dst->size] = 0;
        }
}

void td_ustr_cat_seq(td_ustr_t *dst, const uint32_t *src, size_t size)
{
        td_ustr_ins_seq(dst, src, dst->size, size);
}

void td_ustr_cat_seqc(td_ustr_t *dst, const char *src, size_t size)
{
        td_ustr_ins_seqc(dst, src, dst->size, size);
}

void td_ustr_cat_seqwc(td_ustr_t *dst, const wchar_t *src, size_t size)
{
        td_ustr_ins_seqwc(dst, src, dst->size, size);
}

void td_ustr_sub(
        td_ustr_t *dst,
        const td_ustr_t *src,
        size_t begin,
        size_t size
)
{
        if (begin >= src->size || begin + size > src->size) {
                td_errno = TD_EINDEX;
                return;
        }

        if (dst->cap < size)  {
                td_ustr_free(dst);
                td_ustr_init(dst, size);
        }

        memcpy(dst->slots, &src->slots[begin], size * UCODE_SIZE);
        dst->slots[size] = 0;
        dst->size = size;
}

void td_ustr_erase(td_ustr_t *dst, size_t begin, size_t size)
{
        if (begin >= dst->size || begin + size > dst->size) {
                td_errno = TD_EINDEX;
                return;
        }

        for (size_t i = begin; i < begin + size; ++i)
                dst->slots[i] = dst->slots[begin + size - 1 + i];
        dst->slots[begin + size] = 0;
        dst->size = dst->size - size;
}

void td_ustr_clean(td_ustr_t *s)
{
        s->slots[0] = 0;
        s->size = 0;
}

void td_ustr_lower(td_ustr_t *dst)
{
        for (uint32_t *p = dst->slots; *p != 0; ++p) {
                if (*p >= 0x41 && *p <= 0x5A)
                        *p = *p + 0x20;
        }

}

void td_ustr_upper(td_ustr_t *dst)
{
        for (uint32_t *p = dst->slots; *p != 0; ++p) {
                if (*p >= 0x61 && *p <= 0x7A)
                        *p = *p - 0x20;
        }
}

uint32_t td_ustr_get(td_ustr_t *dst, size_t index)
{
        if (index >= dst->size) {
                td_errno = TD_EINDEX;
                return 0;
        }
        return dst->slots[index];
}

void td_ustr_set(td_ustr_t *dst, size_t index, uint32_t code)
{
        if (index >= dst->size) {
                td_errno = TD_EINDEX;
                return;
        }
        dst->slots[index] = code;
}

void td_ustr_setc(td_ustr_t *dst, size_t index, char code)
{
        if (index >= dst->size) {
                td_errno = TD_EINDEX;
                return;
        }
        dst->slots[index] = code;
}

void td_ustr_setwc(td_ustr_t *dst, size_t index, wchar_t code)
{
        if (index >= dst->size) {
                td_errno = TD_EINDEX;
                return;
        }
        dst->slots[index] = code;
}
