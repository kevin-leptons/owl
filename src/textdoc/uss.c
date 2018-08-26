#include <textdoc/uss.h>

#include <wchar.h>

#include <textdoc/error.h>

void td_uss_init(td_uss_t *s, const char *file) {
        s->fs = fopen(file, "r,ccs=UTF-8");
        if (!s->fs) {
                td_errno = errno;
                return;
        }
}

void td_uss_free(td_uss_t *s) {
        fclose(s->fs);
}

uint32_t td_uss_getc(td_uss_t *s) {
        errno = 0;
        td_errno = TD_ENONE;
        uint32_t c = fgetwc(s->fs);
        if (!errno && c == WEOF) {
                td_errno = TD_EEND;
                return 0;
        }
        if (errno) {
                td_errno = errno;
                return 0;
        }
        return c;
}
void td_uss_write(td_uss_t *s, uint32_t symbol);
