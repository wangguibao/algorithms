/*
 * multiply-list-represented-integers.c
 * Two numbers represented as linked lists (Bigger than integers). Return a
 * linked list that is the product of the given two linked lists:
 * Input: 1->2->3->NULL, 2->3-> NULL
 * Output: 2->8->2->9->NULL
 *
 * From http://www.geeksforgeeks.org/amazon-interview-set-21/
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct _NODE NODE;

struct _NODE {
    int n;
    NODE *next;
};

/*
 * Print out the number represented by the linked-list
 */
void print_list(NODE *p)
{
    while (p != NULL) {
        printf("%d", p->n);
        p = p->next;
    }

    printf("\n");
    return;
}

/*
 * Ugly code to initialize the two linked list
 * Change at will to make them represent any number
 */
void init_lists(NODE *m1, NODE *m2)
{
    NODE *p = m1;
    p->n = 1;

    /* Set m1 represent 103 */
    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 0;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 3;

    p->next = NULL;

    /* Set m2 represent 2091 */
    p = m2;
    p->n = 2;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 0;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 9;

    p->next = malloc(sizeof(NODE));
    p = p->next;
    p->n = 1;

    p->next = NULL;
}

/*
 * Reverses the list
 */
NODE * reverse_list(NODE *m)
{
    NODE *prev = NULL;
    NODE *p = m;
    NODE *next;

    while (p != NULL) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    return prev;
}

/*
 * Destroy the list
 */
void destroy_list(NODE *m)
{
    NODE *p = m;
    NODE *next;

    while (p != NULL) {
        next = p->next;
        free(p);
        p = next;
    }
}

/*
 * Multiply the list-represented integer by a single digit
 *
 * m1         - the list to be multiplied by multiplier
 * multiplier - a single digit
 * result     - resultant linked-list
 */
int multiply_to(NODE *m1, int multiplier, NODE **result)
{
    int carrier = 0;
    int product;
    NODE *p = m1;
    NODE *temp;
    NODE *prev;

    assert(*result != NULL);
    temp = *result;
    prev = temp;

    while (p != NULL) {
        product = p->n * multiplier + carrier;

        if (temp == NULL) {
            temp = malloc(sizeof(NODE));
            prev->next = temp;
        }
        temp->n = product % 10;
        carrier = product / 10;
        prev = temp;
        temp = temp->next;

        p = p->next;
    }

    if (temp != NULL) {
        temp->n = -1;     // Indicating end of list
    }

    return 0;
}

/*
 * Multiply the list by 10.
 * The list will be manipulated in-place
 *
 * m1   - the linked-list that is to be multiplied
 * time - number of times the linked-list will be multiplied by 10
 */
void multiply_to_10(NODE **m1, int time)
{
    NODE *p;
    NODE *new;

    if (*m1 == NULL) {
        return;
    }
    p = *m1;

    while (time > 0) {
        new = malloc(sizeof(NODE));
        new->n = 0;
        new->next = p;
        p = new;
        time--;
    }
    *m1 = p;

    return;
}

/*
 * Add two linked list
 *
 * dst - the augend
 * src - the addend
 */
void add_to(NODE **dst, NODE **src)
{
    NODE *p1 = *dst;
    NODE *p1_prev = p1;
    NODE *p2 = *src;
    NODE *temp;
    int carrier = 0;
    int sum;

    while (p1 != NULL && p2 != NULL && p2->n != -1) {
        sum = p1->n + p2->n + carrier;
        p1->n = sum % 10;
        carrier = sum / 10;

        p1_prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    p1 = p1_prev;
    while (p2 != NULL && p2->n != -1) {
        sum = p2->n + carrier;
        temp = malloc(sizeof(NODE));
        temp->n = sum % 10;
        carrier = sum / 10;

        p1->next = temp;
        p1 = p1->next;

        p2 = p2->next;
    }

    if (carrier > 0) {
        temp = malloc(sizeof(NODE));
        temp->n = carrier;
        temp->next = NULL;
        p1->next = temp;
    }

    return;
}

/*
 * Multiply two linked-lists
 *
 * m1 - multiplicand
 * m2 - multiplier
 * returns a linked list
 */
NODE * multiply(NODE *m1, NODE *m2)
{
    NODE *p1 = reverse_list(m1);
    NODE *p2 = reverse_list(m2);
    NODE *temp = malloc(sizeof(NODE));
    NODE *result = malloc(sizeof(NODE));
    int multiplier;
    int loop = 0;

    while (p2 != NULL) {
        multiplier = p2->n;
        p2 = p2->next;

        if (loop == 0) {
            multiply_to(p1, multiplier, &result);
            loop = 1;
        }
        else {
            multiply_to(p1, multiplier, &temp);
            multiply_to_10(&temp, loop);
            add_to(&result, &temp);
            loop++;
        }
    }

    destroy_list(temp);

    return reverse_list(result);
}

int main()
{
    NODE *result = NULL;

    NODE *m1 = malloc(sizeof(NODE));
    NODE *m2 = malloc(sizeof(NODE));

    init_lists(m1, m2); 
    print_list(m1);
    print_list(m2);

    result = multiply(m1, m2);
    print_list(result);

    destroy_list(result);
    destroy_list(m1);
    destroy_list(m2);

    return 0;
}

