#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>

// creates a Union_find datastructure
UNION_FIND createUF(int n)
{
    UNION_FIND F;
    F.ptr = (NODE_PTR *)malloc(n * sizeof(NODE_PTR));

    for (int i = 0; i < n; i++)
        F.ptr[i] = NULL;
    F.size = n;

    return F;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i)
{

    NODE_PTR node = (NODE_PTR)malloc(sizeof(struct _NODE));
    node->value = x;
    node->count_nodes = 1;
    node->parent = NULL;

    // store node pointer in a position which has NULL value
    for (int index = 0; index < F.size; index++)
    {
        if (F.ptr[index] == NULL)
        {
            F.ptr[index] = node;
            *i = index;
            break;
        }
    }
    return F;
}

// returns pointer to the root node of set which contains given node
NODE_PTR findUF(UNION_FIND F, int i)
{
    NODE_PTR curr = F.ptr[i];
    if (curr == NULL)
        return NULL;

    while (curr->parent != NULL)
    {
        curr = curr->parent;
    }
    return curr;
}

// make union of sets containing given two node
void unionUF(UNION_FIND F, int i, int j)
{
    NODE_PTR root1, root2;
    root1 = findUF(F, i);
    root2 = findUF(F, j);

    if (root1 == root2)
        return;

    if (root1->count_nodes > root2->count_nodes)
    {
        root2->parent = root1;
        root1->count_nodes += root2->count_nodes;
        return;
    }

    root1->parent = root2;
    root2->count_nodes += root1->count_nodes;
}
