#ifndef LLIST_H
#define LLIST_H

#include "Node.h"

typedef struct {
    Node *head, *tail;
    unsigned int size;
} List;

List *newList(void *data, const Bool allocd, const Type type, Status *status);

List *append_list(List *l, void *data, const Bool allocd, const Type type, Status *status);
List *prepend_list(List *l, void *data, const Bool allocd, const Type type, Status *status);

void print_list(List *l);
List *pop_list(List *l, void **sav);
List *destroy_list(List *l);

#endif // LLIST_H
