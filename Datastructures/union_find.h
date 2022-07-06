#ifndef UNION_FIND_H
#define UNION_FIND_H

#ifndef SIZE
#define SIZE 100
#endif

struct _NODE
{
    int value;
    int count_nodes;
    struct _NODE *parent;
};

typedef struct _NODE *NODE_PTR;

typedef struct
{
    NODE_PTR *ptr;
    int size;
} UNION_FIND;

UNION_FIND createUF(int n);
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i);
NODE_PTR findUF(UNION_FIND F, int i);
void unionUF(UNION_FIND F, int i, int j);
#endif