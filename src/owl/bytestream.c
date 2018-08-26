#include <owl/bytestream.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void fill_buff_(td_bytestream_t *s) {
    errno = 0;
    s->buff_size = read(s->fd, s->buff, s->buff_cap);
    if (errno) {
        td_errno = errno;
        return;
    }
    s->buff_offset = 0;
    s->line_num = 0;
    s->col_num = 0;
}

void td_bytestream_init(td_bytestream_t *s, const char *file,
                        size_t buff_cap) {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        td_errno = errno;
        return;
    }

    char *buff = malloc(buff_cap);
    if (!buff) {
        close(fd);
        td_errno = errno;
        return;
    }
    s->fd = fd;
    s->buff = buff;
    s->buff_cap = buff_cap;
    s->buff_size = 0;
    s->buff_offset = 0;
}

void td_bytestream_free(td_bytestream_t *s) {
    close(s->fd);
    s->fd = -1;
    free(s->buff);
    s->buff = NULL;
}

char td_bytestream_read(td_bytestream_t *s) {
    if (s->buff_offset == s->buff_size) {
        fill_buff_(s);
        if (td_errno != TD_ENONE)
            return 0;
    }
    if (s->buff_offset == s->buff_size) {
        td_errno = TD_EEND;
        return 0;
    }
    char byte = s->buff[s->buff_offset];
    s->buff_offset++;
    if (byte == 0x0d || byte == 0x0a || s->line_num == 0)
        s->line_num += 1;
    s->col_num += 1;
    return byte;
}

void td_bytestream_reset(td_bytestream_t *s) {
    if (lseek(s->fd, 0, SEEK_SET))
        td_errno = errno;
}

size_t td_bytestream_line(td_bytestream_t *s) {
    return s->line_num;
}

size_t td_bytestream_col(td_bytestream_t *s) {
    return s->col_num;
}
