#include <textdoc/lexer.h>

void td_lexer_init(td_lexer_t *l, td_bytestream_t *s) {
        l->s = s;
}

void td_lexer_free(td_lexer_t *l) {
        td_bytestream_free(l->s);
}

struct td_token *td_lexer_read(td_lexer_t *l) {
        return NULL;
}
