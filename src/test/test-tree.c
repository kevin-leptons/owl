#include <owl/tree.h>
#include <owl/error.h>

int main(int argc, char *argv[]) {
    struct td_tree *root;
    struct td_tree *leaf;

    root = td_tree_init();
    if (td_errno != TD_ENONE)
        return -1;

    for (size_t i = 0; i < 8; ++i) {
        leaf = td_tree_init();
        if (td_errno != TD_ENONE)
            return -1;
        td_tree_leaf_add(root, leaf);
        if (td_errno != TD_ENONE)
            return -1;
    }

    td_tree_free(root);
}
