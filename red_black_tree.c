/*
 * red_black_tree.c
 * 2-3-4 tree based red black tree implemeatation. Currently only tree insert and serach implemented
 *
 * Author: Wang Guibao <wang_guibao#163.com>
 */
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

/**
 * rotate_right
 * Perform right rotation on a tree node
 * @param head  node on which right rotation is to be performed
 * @return new node in place of old node on which right rotation performed
 */
NODE *rotate_right(NODE *head)
{
    NODE *x;

    if (head == z || head->left == z) {
        printf("rotate_right invalid\n");
        return head;
    }
    x = head->left;
    head->left = x->right;
    x->right = head;

    return x;
}

/**
 * rotate_left
 * Perform left rotation on a tree node
 * @param head  node on which left rotation is to be performed
 * @return new node in place of old node on which left rotation performed
 */
NODE *rotate_left(NODE *head)
{
    NODE *x;
    if (head == z || head->right == z) {
        printf("rotate_left invalid\n");
        return head;
    }

    x = head->right;
    head->right = x->left;
    x->left = head;

    return x;
}

/**
 * rbtree_insert
 * Insert a new element into a red black tree. The philosophy is to understand the code as red-black
 * tree representation of 2-3-4 tree. The insertion serves to break up 4-nodes on the way down to
 * insertion point, and adjust tree nodes to fix the 2-3-4 tree properties on the way up to root
 *
 * @param head  root of red black tree
 * @param datum element to be inserted
 * @param direction direction along the way down to the leaf
 *
 * @return new root of the red black tree
 */
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

        if (head->left->color == RED && head->left->left != z &&
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

        if (head->right->color == RED && head->right->right != z &&
            head->right->right->color == RED) {
            head = rotate_left(head);
            head->color = BLACK;
            head->left->color = RED;
        }
    }

    return head;
}

/**
 * tree_insert
 * Insert an element to a BST. Uses rbtree_insert as implementation
 * @param datum element to be inserted
 */
void tree_insert(char datum)
{
    h = rbtree_insert(h, datum, LEFT);
    h->color = BLACK;
}

void tree_init()
{
    sentinel.datum = '\0';
    sentinel.left = sentinel.right = NULL;
    z = h = &sentinel;
    return;
}

void tree_visit(TREE_NODE *tree)
{
    printf("%c\n", ((NODE *)tree)->datum);
}

/**
 * tree_search
 * Standard BST search routine. Prints the path along the way.
 * @param head  root of the BST
 * @param datum element to be searched
 */
void tree_search(NODE *head, char datum)
{
    if (head == z) {
        return;
    }

    if (head->datum == datum) {
        printf("%c\n", head->datum);
        printf("found\n");
        return;
    }
    else if (datum < head->datum) {
        printf("%c --> ", head->datum);
        tree_search(head->left, datum);
    }
    else {
        printf("%c --> ", head->datum);
        tree_search(head->right, datum);
    }
}

int main()
{
    char *str = "ASERCHINGX";
    int n = strlen(str);
    int i;

    tree_init();
    for (i = 0; i < n; i++) {
        tree_insert(str[i]);
    }

    printf("========Tree structure===========\n");
    tu_init();
    tu_print_tree((TREE_NODE *)h, RIGHT, tree_visit);
    printf("=================================\n");

    printf("Searching X\n");
    tree_search(h, 'X');

    return 0;
}
