#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "LList.h"

List *newList(void *data, const Bool allocd, const Type type, Status *status) {
    List *l = malloc(sizeof(*l));
    if (l == NULL) {
        *status = Failed;
        goto done;
    }

    l->size = 0;
    Status headStatus;
    l->head =  newNode(data, allocd, type, &headStatus);
    if (headStatus == Success) {
        l->size += 1;
        *status = headStatus;
    }
    l->tail = NULL;

done:
    return l;
}

static List *__add_to_list(List *l, void *data, const Bool allocd,
                         const Type type, Status **status, const Bool prepend) {
    if (l == NULL) {
        l = newList(data, allocd, type, *status);
    } else if (l->head == NULL) {
        l->head = append_node(l->head, data, allocd, type);
    } else {
        if (prepend)
            l->head = prepend_node(l->head, data, allocd, type);
        else
            l->tail = append_node(l->tail, data, allocd, type);

        if (l->head->next == NULL) {
            l->head->next = l->tail;
        }
    }

    return l;
}

List *prepend_list(List *l, void *data, const Bool allocd, const Type type, Status *status) {
    return __add_to_list(l, data, allocd, type, &status, True);
}

List *append_list(List *l, void *data, const Bool allocd, const Type type, Status *status) {
    return __add_to_list(l, data, allocd, type, &status, False);
}

void print_list(List *l) {
    printf("[");
    walk_node(l->head, print_lone_node);
    printf("]\n");
}

List *pop_list(List *l, void **sav) {
    if (l == NULL) {
        goto done;
    }

    if (l->head == NULL) {
        if (l->tail == NULL)
            l->size = 0;

        goto done;
    }

    *sav = l->head->data;
    Node *prev = l->head;
    l->head = destroy_lone_node(l->head, False);
    if (l->tail == prev) { // Case of tail pointing to head
        l->tail = NULL;
    }

    // TODO: Could probably use an ASSERT to ensure consistency
    l->size -= 1;

done:
    return l;
}

List *destroy_list(List *l) {
    if (l == NULL)
        goto done;

    Node *orig_head = l->head;
    l->head = destroy_node(l->head, NULL);
    l->tail = destroy_node(l->tail, orig_head);

    free(l);
    l = NULL;

done:
    return l;
}
