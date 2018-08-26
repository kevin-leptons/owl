#include <owl/tree.h>

#include <owl/error.h>

struct td_tree *td_tree_init(void) {
    struct td_tree *t;
    
    t = malloc(sizeof(*t));
    if (!t) {
        td_errno = errno;
        return NULL;
    }
    td_list_init(&t->leafs);
    t->data = NULL;
    return t;
}

void td_tree_free(struct td_tree *t) {
    if (td_list_size(&t->leafs) == 0) {
        free(t);
        return;
    } 

    td_list_slot_t *slot;
    td_list_slot_t *end;
    struct td_tree *leaf;
    slot = td_list_begin(&t->leafs);
    end = td_list_end(&t->leafs);
    for (; slot != end; slot = td_list_next(slot)) {
        leaf = td_list_item(slot);
        td_tree_free(leaf);
    }
    td_list_free(&t->leafs);
    free(t);
}

void td_tree_leaf_add(struct td_tree *t, struct td_tree *leaf) {
    td_list_pushback(&t->leafs, (void *) leaf);
}

void td_tree_dfs(struct td_tree *t,
                 bool (callback)(struct td_tree *leaf, void *arg),
                 void *arg) {

}
