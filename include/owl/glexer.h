/*
	Context Free Grammar lexer
*/

#ifndef TD_GLEXER_H
#define TD_GLEXER_H

#include <owl/uss.h>
#include <owl/ustr.h>

enum td_glexer_token_id {
    td_glexer_token_whitespace,
    td_glexer_token_dec,
    td_glexer_token_hex,
    td_glexer_token_id,
    td_glexer_token_assign,
    td_glexer_token_vbar,
    td_glexer_token_asterisk,
    td_glexer_token_plus,
    td_glexer_token_pt_open,
    td_glexer_token_pt_close,
    td_glexer_token_brace_open,
    td_glexer_token_brace_close,
    td_glexer_token_comma,
    td_glexer_token_semicolon,
    td_glexer_token_inline_comment,
    td_glexer_token_block_comment,
};

struct td_glexer_token {
	enum td_glexer_token_id id;
    td_ustr_t value; 
};

typedef struct {
    td_uss_t *stream;
    td_ustr_t token_value; 
} td_glexer_t;

void td_glexer_init(td_glexer_t *lex, td_uss_t *stream);
void td_glexer_free(td_glexer_t *lex);
void td_glexer_next(td_glexer_t *lex, struct td_glexer_token *token);

void td_glexer_token_init(struct td_glexer_token *token);
void td_glexer_token_free(struct td_glexer_token *token);

#endif
