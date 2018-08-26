#ifndef TEXTDOC_DOC_H
#define TEXTDOC_DOC_H

#include <stdlib.h>

#include <owl/list.h>

#define TD_TAG_NAME 1
#define TD_TAG_VERSION 2
#define TD_TAG_LICENSES 3
#define TD_TAG_AUTHORS 4
#define TD_TAG_VARIABLE 5
#define TD_TAG_H1 6
#define TD_TAG_H2 7
#define TD_TAG_H3 8
#define TD_TAG_H4 9
#define TD_TAG_H5 10
#define TD_TAG_H6 11
#define TD_TAG_P 12
#define TD_TAG_CODE 13
#define TD_TAG_IMG 14
#define TD_TAG_TABLE 15

struct td_node {
    const char *id;
    size_t tagname;
};

struct td_node_name {
struct td_node node;
const char *value;
};

struct td_node_version {
    struct td_node node;
    const char *value;
};

struct td_node_licenses {
    struct td_node node;
    td_list_t values; // list of strings
};

struct td_node_authors {
    struct td_node node;
    td_list_t values; // list of strings
};

struct td_node_variables {
    struct td_node node;
    td_list_t values; // list of strings
};

struct td_node_h1 {
    struct td_node node;
    const char *title;
};

struct td_node_h2 {
    struct td_node node;
    const char *title;
};

struct td_node_h3 {
    struct td_node node;
    const char *title;
};

struct td_node_h4 {
    struct td_node node;
    const char *title;
};

struct td_node_h5 {
    struct td_node node;
    const char *title;
};

struct td_node_h6 {
    struct td_node node;
    const char *title;
};

struct td_node_p {
    struct td_node node;
    const char *content;
};

struct td_node_code {
    struct td_node node;
    const char *content;
};

struct td_node_img {
    struct td_node node;
    const char *file;
};

struct td_node_table {
    struct td_node node;
    const char *content;
};

#endif
