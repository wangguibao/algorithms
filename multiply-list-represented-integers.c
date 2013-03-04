#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE NODE;

struct _NODE {
    int n;
    NODE *next;
};

NODE *m1;
NODE *m2;

void init_lists(NODE *m1, NODE *m2)
{
    NODE *p = m1;
    p->n = 1;

    /* Set m1 represent 123 */
    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 2;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 3;

    p->next = NULL;

    /* Set m2 represent 23 */
    p = m2;
    p->n = 2;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 3;

    p->next = NULL;
}

int multiply_to(NODE *m1, int multiplier)
{
    int carrier = 0;
    int result;
    NODE *p = m1;

    if (p->next != NULL) {
        carrier = multiply_to(p->next, multiplier);
    }
    result = p->n * multiplier + carrier;
    p->n = result % 10;

    return result / 10;
}

void multiply_to_10(NODE *m1)
{
    NODE *p = p1;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 0;

    p->next = NULL;
}

void multiply(NODE *m1, NODE *m2)
{
    NODE *p1 = m1;
    NODE *p2 = m2;
    NODE *p = p1;
    int multiplier;

    while (p2 != NULL) {
        multiplier = p2->n;
        p2 = p2->next;

        if (multiplier == 0) {
        multiply_to_10(p1);
        }
        else {
            int carrier = multiply_to(p1, multiplier);
            if (carrier > 0) {
                p = malloc(sizeof(NODE));
                p->n = carrier;
                p->next = p1;
                p1 = p;
            }
        }
    }
}

void print_list()
{
    NODE *p = m1;
    while (p != NULL) {
        printf("%d", p->n);
        p = p->next;
    }

    printf("\n");
    return;
}

int main()
{
    m1 = malloc(sizeof(NODE));
    m2 = malloc(sizeof(NODE));
    init_lists(m1, m2); 
    multiply(m1, m2);

    print_list();
    return 0;
}
