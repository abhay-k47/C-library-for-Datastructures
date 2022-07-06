#ifndef LIST_H
#define LIST_H
typedef struct _ND
{
    int value;
    struct _ND *next;
} NODE;

typedef struct _LLIST{
    NODE * head;
} LLIST;

LLIST createList();
int searchList(LLIST H, int k);
LLIST insertAtFront(LLIST H, int k);
LLIST insertAtEnd(LLIST H, int k);
LLIST deleteFromFront(LLIST H, int *k);
LLIST deleteFromEnd(LLIST H, int *k);
LLIST deleteList(LLIST H, int k);

#endif