/**
* list-reverse.c: reverse a single linked list. The single-linked list doesn't
* have a leading head
*
* @author Wang Guibao
* @date 2012-10-25
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ELE 10

typedef struct _NODE {
    int d;
    struct _NODE *next;
} NODE;

NODE list[MAX_ELE];

NODE* new_list()
{
    int i;
    int d;

    for (i = 0; i < MAX_ELE; i++) {
        d = rand() % 100;
        list[i].d = d;
        list[i].next = &list[i + 1];
    }
    list[MAX_ELE - 1].next = NULL;

    return &list[0];
}

void travese_list(NODE *plist)
{
    NODE *current = plist;
    while (current != NULL) {
        printf("%d->", current->d);
        current = current->next;
    }
    printf("\n");

    return;
}

NODE* reverse_list(NODE *plist)
{
    NODE *prev = NULL;
    NODE *q = plist;
    NODE *p;

    if (plist == NULL) {
        return plist;
    }

   while (q != NULL) {
        p = q;
        q = q->next;
        p->next = prev;
        prev = p;
    }

    return p;
}

int main()
{
    NODE *l;

    srand(time(NULL));

    l = new_list();
    travese_list(l);

    l = reverse_list(l);
    travese_list(l);

    return 0;
}
