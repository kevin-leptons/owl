#include <owl/parser.h>

#include <stdio.h>

#include <owl/bytestream.h>

struct td_tree *td_parse(const char *file) {
    td_bytestream_t s;

    td_bytestream_init(&s, file, 1024);
    if (td_errno != TD_ENONE)
        return NULL;

    char byte;
    for (;;) {
        byte = td_bytestream_read(&s) ;
        if (td_errno == TD_ENONE) {
            printf("%c", byte);
        } else if (td_errno == TD_EEND) {
            td_errno = TD_ENONE;
            return NULL;
        } else {
            return NULL;
        }
    }
}
