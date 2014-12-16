#ifndef DEFS_H
#define DEFS_H

typedef enum {
    Failed = -1, Success = 0,
    NoMem, Unknown,
} Status;

typedef enum {
    Undef=-2, Other=-1, Int=1, Char=2, Ptr=3, Void=4,
    Func, LInt, CharPtr,
} Type;

typedef enum {
    False=0, True=1
} Bool;

void print_data(void *data, const Type type);
#endif // DEFS_H
