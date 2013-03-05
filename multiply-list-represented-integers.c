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

int multiply_to(NODE *m1, int multiplier, NODE *p_result)
{
    int carrier = 0;
    int product;
    NODE *p = m1;
    NODE *p_temp;

    if (p->next != NULL) {
        carrier = multiply_to(p->next, multiplier, p_result);
    }

    product = p->n * multiplier + carrier;
    p_temp = malloc(sizeof(NODE));
    p_temp->n = product % 10;
    p_temp->next = p_result;
    p_result = p_temp;

    return product / 10;
}

void multiply_to_10(NODE *m1)
{
    NODE *p = m1;

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
    NODE *p_temp = NULL;
    NODE *p_result = NULL;
    int multiplier;

    while (p2 != NULL) {
        multiplier = p2->n;
        p2 = p2->next;

        if (multiplier == 0 && p_temp != NULL) {
            multiply_to_10(p_temp);
        }
        else {
            int carrier = multiply_to(p1, multiplier, p_temp);
            if (carrier > 0) {
                NODE *p = malloc(sizeof(NODE));
                p->n = carrier;
                p->next = p_temp;
                p_temp = p;
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
