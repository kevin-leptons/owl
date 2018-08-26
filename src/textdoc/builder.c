#include <textdoc/builder.h>

#include <textdoc/parser.h>
#include <textdoc/tree.h>

static bool html_callback_(struct td_tree *leaf, void *arg) {
        return false;
}

void td_build_html(const char *src, const char *dest) {
        struct td_tree *root;
        root = td_parse(src);
        td_tree_dfs(root, html_callback_, NULL);
}

void td_build_pdf(const char *src, const char *dest) {

}
