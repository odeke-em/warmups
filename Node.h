#ifndef NODE_H
#define NODE_H

#include "defs.h"

typedef struct Node {
    struct Node *next;
    void *data;
    Type type;
    unsigned int allocd:1;
} Node;

typedef void (*VoidMapper)(Node *n);

Node *newNode(void *data, const Bool allocd, const Type type, Status *status);
Node *append_node(Node *n, void *data, const Bool allocd, const Type type);
Node *prepend_node(Node *n, void *data, const Bool allocd, const Type type);

Node *destroy_node(Node *n, const Node *sentinel);
Node *destroy_lone_node(Node *n, const Bool free_node);

void print_lone_node(Node *n);
void walk_node(Node *n, VoidMapper func);

#endif // NODE_H
