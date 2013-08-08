#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "treeutil.h"

typedef struct _NODE NODE;
struct _NODE {
    NODE *left;
    NODE *right;
    char datum;
    int color;
};

typedef enum _COLOR {
    BLACK = 0,
    RED,
} COLOR;

NODE sentinel;
NODE *z;
NODE *h;

NODE *new_node(char c, NODE *left, NODE *right, int color)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL) {
        return NULL;
    }

    node->datum = c;
    node->left = left;
    node->right = right;
    node->color = color;

    return node;
}

NODE *rotate_right(NODE *head)
{
    NODE *x;

    if (head == NULL || head->left == NULL) {
        printf("rotate_right invalid\n");
        return head;
    }
    x = head->left;
    head->left = x->right;
    x->right = head;

    return x;
}

NODE *rotate_left(NODE *head)
{
    NODE *x;
    if (head == NULL || head->right == NULL) {
        printf("rotate_left invalid\n");
        return head;
    }

    x = head->left;
    head->right = x->left;
    x->left = head;

    return x;
}

NODE *rbtree_insert(NODE *head, char datum, DIRECTION direction)
{
    if (head == z) {
        return new_node(datum, z, z, RED);
    }

    if (head->left->color == RED && head->right->color == RED) {
        head->left->color = BLACK;
        head->right->color = BLACK;
        head->color = RED;
    }

    if (datum < head->datum) {
        head->left = rbtree_insert(head->left, datum, LEFT);
        if (head->color==RED && head->left->color==RED && direction==RIGHT) {
            head = rotate_right(head);
        }

        if (head->left->color == RED && head->left->left != NULL &&
            head->left->left->color == RED) {
            head = rotate_right(head);
            head->color = BLACK;
            head->right->color = RED;
        }
    }
    else {
        head->right = rbtree_insert(head->right, datum, RIGHT);
        if (head->color==RED && head->right->color== RED && direction== LEFT) {
            head = rotate_left(head);
        }

        if (head->left->color == RED && head->right->right != NULL &&
            head->right->right->color == RED) {
            head = rotate_left(head);
            head->color = BLACK;
            head->left->color = RED;
        }
    }

    return head;
}

NODE *tree_insert(char datum)
{
    return rbtree_insert(h, datum, LEFT);
}

NODE *tree_init()
{
    sentinel.datum = '\0';
    sentinel.left = sentinel.right = &sentinel;
    z = h = &sentinel;
    return h;
}

void tree_visit(TREE_NODE *tree)
{
    printf("%c\n", ((NODE *)tree)->datum);
}

NODE *tree_search(NODE *head, char datum)
{
    NODE *node;
    if (head == NULL) {
        return NULL;
    }

    if (head->datum == datum) {
        printf("found\n");
        return head;
    }

    if ((node = tree_search(head->left, datum)) != NULL) {
        return node;
    }
    return tree_search(head->right, datum);
}

int main()
{
    char *str = "ASERCHINGX";
    NODE *tree = tree_init();
    int n = strlen(str);
    int i;

    for (i = 0; i < n; i++) {
        tree = tree_insert(str[i]);
    }

    tree_search(tree, 'X');

    tu_init();
    tu_print_tree((TREE_NODE *)tree, RIGHT, tree_visit);
    return 0;
}
