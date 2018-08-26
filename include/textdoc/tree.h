#ifndef TEXTDOC_TREE_H
#define TEXTDOC_TREE_H

#include <stdlib.h>
#include <stdbool.h>

#include <textdoc/list.h>

struct td_tree {
        td_list_t leafs;
        void *data;
};

struct td_tree *td_tree_init(void);
void td_tree_free(struct td_tree *t);
void td_tree_leaf_add(struct td_tree *t, struct td_tree *leaf);
void td_tree_dfs(struct td_tree *t,
                 bool (callback)(struct td_tree *leaf, void *arg),
                 void *arg);

#endif
