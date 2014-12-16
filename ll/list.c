#include <stdio.h>
#include <stdlib.h>

#include "Node.h"
#include "LList.h"
#include "azzert.h"

int main() {
    Status status;
    List *l = newList(__FILE__, False, CharPtr, &status);
    ASSERT(l != NULL, "l shouldn't be NULL!");

    int d = 10;
    const char *s = __func__;
    l = append_list(l, l, False, Undef, &status);
    print_lone_node(l->head);
    l = append_list(l, &d, False, Int, &status);
    l = append_list(l, s, False, CharPtr, &status);

    print_list(l);

    l = destroy_list(l);

    return 0;
}
