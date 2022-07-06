#ifndef HEAP_H
#define HEAP_H

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

typedef struct
{
    int *list;
    int size;
} HEAP;
HEAP createHeap();
int findMin(HEAP H);
int isFullHeap(HEAP H);
int isEmptyHeap(HEAP H);
HEAP insertHeap(HEAP H, int k);
HEAP extractMin(HEAP H);

#endif
