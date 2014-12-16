#include <stdio.h>
#include <stdlib.h>

#include "azzert.h"
#include "defs.h"
#include "Node.h"

int main() {
    Status status;
    Node *n = newNode((void *)main, False, Func, &status);
    ASSERT(status == Success, "Successful operation expected instead got: %d", status);
    ASSERT(n != NULL, "n should not be NULL");
    ASSERT(n->data != NULL, "n should not be NULL");
    ASSERT(n->data == main, "Expected data to point at: %p instead got :%p", main, n->data);

    n = destroy_node(n, (Node *)main);
    ASSERT(n == NULL, "Expected at least n to be set to NULL after destruction!");

    return 0;
}
