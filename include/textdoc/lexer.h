#ifndef TEXTDOC_LEXER_H
#define TEXTDOC_LEXER_H

#include <textdoc/bytestream.h>

enum td_token_type {
        td_token_keyword,
        td_token_string
};

typedef struct {
        td_bytestream_t *s;
} td_lexer_t;

struct td_token {
        enum td_token_type type;
        const char *value;
};

void td_lexer_init(td_lexer_t *l, td_bytestream_t *s);
void td_lexer_free(td_lexer_t *l);
struct td_token *td_lexer_read(td_lexer_t *l);

#endif
