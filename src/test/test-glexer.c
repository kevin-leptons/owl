#include <wchar.h>

#include <textdoc/glexer.h>
#include <textdoc/error.h>

int main(int argc, char *argv[]) {
        td_glexer_t lex;
        td_uss_t stream;

        if (argc != 3)
                return 1;

        td_uss_init(&stream, argv[1]);
        if (td_errno != TD_ENONE)
                return 1;

        td_glexer_init(&lex, &stream);
        if (td_errno != TD_ENONE)
                return 1;

        struct td_glexer_token token;
        FILE *of;
        td_glexer_token_init(&token);
        of = fopen(argv[2], "w+,ccs=UTF-8");
        if (!of)
                return 1;
        for (;; ) {
                td_glexer_next(&lex, &token);
                if (!td_errno) {
                        fputws((wchar_t *) token.value.slots, of);
                        fputws(L"\n", of);
                } else if (td_errno == TD_EEND) {
                        break;
                } else {
                        return 1;
                }
        }

        fclose(of);
        td_glexer_token_free(&token);
        td_glexer_free(&lex);
        td_uss_free(&stream);
}
