#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Creates and returns a empty heap
HEAP createHeap()
{
    HEAP H;
    H.list = (int *)malloc(MAX_SIZE * sizeof(int));
    H.size = 0;
    return H;
}

// returns minimum value of heap
int findMin(HEAP H)
{
    return H.list[0];
}

int isFullHeap(HEAP H)
{
    return H.size == MAX_SIZE;
}

int isEmptyHeap(HEAP H)
{
    return H.size == 0;
}

// Inserts a node in heap
HEAP insertHeap(HEAP H, int k)
{
    if (isFullHeap(H))
        return H;

    H.list[H.size] = k;
    H.size++;
    int index = H.size - 1;

    // Heapify
    while (1)
    {
        if (index == 0)
            break;
        int parent = (index - 1) / 2;
        if (H.list[parent] <= H.list[index])
            break;
        swap(&H.list[parent], &H.list[index]);
        index = parent;
    }
    return H;
}

// extracts (delete) minimum value from the heap
HEAP extractMin(HEAP H)
{
    if (isEmptyHeap(H))
        return H;

    H.list[0] = H.list[H.size - 1];
    H.size--;

    // Heapify
    int index = 0;
    while (1)
    {
        int left = 2 * index + 1, right = 2 * index + 2, min = right;

        if (left >= H.size)
            break;
        else if (right >= H.size)
            min = left;
        else if (H.list[left] < H.list[right])
            min = left;
        else
            min = right;

        if (H.list[min] >= H.list[index])
            break;
        else
        {
            swap(&H.list[min], &H.list[index]);
            index = min;
        }
    }
    return H;
}
