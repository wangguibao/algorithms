/*
 * Disjoint set using linked list
 * Implements MAKE_SET, UNION and FIND_SET algorithms
 *
 * Test case directly copied from practice 21.2-2, CLRS 2nd
 */
#include <stdio.h>
#include <stdlib.h>

#define SET_CNT (16 + 1)    /* Number of initial sets */
typedef int ELE_TYPE;       /* Hold data type */

typedef struct _NODE NODE;
typedef struct _SET SET;

struct _NODE {
    ELE_TYPE ele;
    NODE *next;
    NODE *rep;
    SET *set;               /* Which set the node belongs to */
};

struct _SET {
    NODE *head;
    NODE *tail;
    int size;
};

NODE node_array[SET_CNT];
SET set_array[SET_CNT];

void make_set(ELE_TYPE ele)
{
    SET *set;
    NODE *node;

    if (ele < 1 || ele > SET_CNT) {
        return;
    }
    set = &set_array[ele];
    node = &node_array[ele];

    set->head = set->tail = node;
    set->size = 1;

    node->ele = ele;
    node->next = NULL;
    node->rep = node;
    node->set = set;

    return;
}

void union_set(ELE_TYPE left_ele, ELE_TYPE right_ele)
{
    NODE *left_node;
    NODE *right_node;
    NODE *node;
    SET *left;
    SET *right;

    if (left_ele < 1 || left_ele > SET_CNT
        || right_ele < 1 || right_ele > SET_CNT) {
        return;
    }

    left_node = &node_array[left_ele];
    right_node = &node_array[right_ele];
    left = left_node->set;
    right = right_node->set;

    /*
     * The weighted-union rule is also following that of practice 21.2-2,
     * CLRS 2nd: if the sets have the same size, then UNION(xi, xj) appends
     * xj's list onto xi's list
     */
    if (left->size < right->size) {
        right->tail->next = left->head;
        right->tail = left->tail;

        node = left->head;
        while (node != NULL) {
            node->rep = right->head;
            node->set = right;
            node = node->next;
        }

        right->size += left->size;

        left->head = left->tail = NULL;
        left->size = 0;
    }
    else {
        left->tail->next = right->head;
        left->tail = right->tail;

        node = right->head;
        while (node != NULL) {
            node->rep = left->head;
            node->set = left;
            node = node->next;
        }

        left->size += right->size;

        right->head = right->tail = NULL;
        right->size = 0;
    }
}

NODE* find_set(ELE_TYPE ele)
{
    if (ele < 1 || ele > SET_CNT) {
        return NULL;
    }
    return node_array[ele].rep;
}

int main()
{
    int i;
    ELE_TYPE ele;

    for (i = 1;  i <= SET_CNT; i++) {
        ele = (ELE_TYPE)i;
        make_set(ele);
    }

    for (i = 1; i <= SET_CNT - 1; i += 2) {
        union_set(i, i + 1);
    }

    for (i = 1; i <= SET_CNT - 3; i += 4) {
        union_set(i, i + 2);
    }

    union_set(1, 5);
    union_set(11, 13);
    union_set(1, 10);

    printf("%d\n", find_set(2)->ele);
    printf("%d\n", find_set(9)->ele);

    return 0;
}
