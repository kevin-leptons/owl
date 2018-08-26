/*
DESCRIPTION

ERRORS

        TD_EEND on end of stream
*/

#ifndef TD_BYTESTREAM_H
#define TD_BYTESTREAM_H

#include <stdlib.h>
#include <textdoc/error.h>

typedef struct {
        int fd;
        char *buff;
        size_t buff_cap;
        size_t buff_size;
        size_t buff_offset;
        size_t line_num;
        size_t col_num;
} td_bytestream_t;

void td_bytestream_init(td_bytestream_t *s, const char *file,
                        size_t buff_cap);
void td_bytestream_free(td_bytestream_t *s);
char td_bytestream_read(td_bytestream_t *s);
void td_bytestream_reset(td_bytestream_t *s);
size_t td_bytestream_line(td_bytestream_t *s);
size_t td_bytestream_col(td_bytestream_t *s);

#endif
