#include <stdlib.h>
#include <stdio.h>

#include "Node.h"

Node *newNode(void *data, const Bool allocd, const Type type, Status *status) {
    Node *n = malloc(sizeof(*n));
    if (n == NULL) {
        *status = NoMem;
        goto done;
    }

    n->data = data;
    n->type = type;
    n->next = NULL;
    n->allocd = allocd;
    *status = Success;

done:
    return n;
}

static inline Node *_destroy_lone_node(Node *n, const Bool free_node) {
    Node *next = n->next;
    if (n->allocd)
        free(n->data);

    n->data = NULL;
    if (free_node)
        free(n);

    return next;
}

Node *destroy_lone_node(Node *n, const Bool free_node) {
    if (n != NULL)
        n = _destroy_lone_node(n, free_node);

    return n;
}

Node *destroy_node(Node *n, const Node *sentinel) {
    if (n == NULL) {
        goto done;
    }

    while (n != NULL && sentinel != n) {
        n = _destroy_lone_node(n, n->allocd);
    }

done:
    return n;
}

static Node *__add_to_node(Node *n, void *data, const Bool allocd,
                                const Type type, const Bool prepend) {
    Status status;
    if (n == NULL)
        n = newNode(data, allocd, type, &status);
    else {
        Node *tmp = newNode(data, allocd, type, &status);
        if (status != Success) {
            goto done;
        }

        if (prepend) {
            tmp->next = n;
        } else {
            n->next = tmp;
        }

        n = tmp;
    }

done:
    return n;
}

Node *prepend_node(Node *n, void *data, const Bool allocd, const Type type) {
    n = __add_to_node(n, data, allocd, type, True);
    return n;
}

Node *append_node(Node *n, void *data, const Bool allocd, const Type type) {
    n = __add_to_node(n, data, allocd, type, False);
    return n;
}

void print_lone_node(Node *n) {
    printf("{");
    if (n != NULL)
        print_data(n->data, n->type);
    printf("}");
}

void walk_node(Node *n, VoidMapper func) {
    Node *tmp = n;
    while (tmp != NULL) {
        func(tmp);
        tmp = tmp->next;
    }
}
