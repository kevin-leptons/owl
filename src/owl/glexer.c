#include <owl/glexer.h>

#include <wchar.h>


#include <owl/error.h>

void td_glexer_init(td_glexer_t *lex, td_uss_t *stream) {
	lex->stream = stream;
        td_ustr_init(&lex->token_value, 1024);
}

void td_glexer_free(td_glexer_t *lex) {
        lex->stream = NULL;
        td_ustr_free(&lex->token_value);
}

void td_glexer_next(td_glexer_t *lex, struct td_glexer_token *token) {
    uint32_t c;
    
    td_ustr_clean(&lex->token_value);
    for (;;) {
        c = td_uss_getc(lex->stream);
        if (td_errno)
                return;
        if (c == 0x20 || c == 0x0D || c == 0x0A) {
            if (lex->token_value.size == 0)
                continue;
            td_ustr_copy(&token->value, &lex->token_value);
            return;
        }
        td_ustr_pub(&lex->token_value, c);
    }
}

void td_glexer_token_init(struct td_glexer_token *token) {
    td_ustr_init(&token->value, 0);
}

void td_glexer_token_free(struct td_glexer_token *token) {
    td_ustr_free(&token->value);
}
