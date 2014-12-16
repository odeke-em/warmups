#include <stdio.h>
#include "defs.h"

static void _print_int(void *d) {
    if (d == NULL)
        printf("0");
    else
        printf("%d", *(int *)d);
}

static void _print_longint(void *d) {
    if (d == NULL)
        printf("0");
    else
        printf("%ld", *(long int *)d);
}

static void _print_char(void *d) {
    if (d == NULL)
        putchar('\0');
    else
        printf("%c", *(char *)d);
}

static void _print_charptr(void *d) {
    printf("%s", (char *)d);
}

static void _print_ptr(void *d) {
    printf("%p", d);
}

void print_data(void *data, const Type type) {
    switch (type) {
        case Int:
            _print_int(data);
        break;
        case LInt:
            _print_longint(data);
        break;
        case Char:
            _print_char(data);
        break;
        case CharPtr:
            _print_charptr(data);
        break;
        default:
            _print_ptr(data);
    }
}

