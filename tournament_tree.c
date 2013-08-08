/*
 * tournament_tree.c - constructs a tournament tree from an array
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELE 16  /* Max number of elements */

typedef struct _NODE {
    int n;
    struct _NODE *left;
    struct _NODE *right;
} NODE;

typedef enum {LEFT, RIGHT} DIRECTION;

char indent[(MAX_ELE + 1) * 2];

/*
 * print_tree
 * Prints out binary tree in a structural manner
 * @param tree      root of the binary tree
 * @param dir       left or right child
 * @param indent    indent string before each row
 */
void print_tree(NODE *tree, DIRECTION dir, char *indent)
{
    if (tree != NULL) {
        printf("%s", indent);

        if (dir == LEFT) {
            printf("|-");
            strcat(indent, "| ");
        }
        else {
            printf("\\-");
            strcat(indent, "  ");
        }
        printf("%d\n", tree->n);

        print_tree(tree->left, LEFT, indent);
        print_tree(tree->right, RIGHT, indent);
        indent[strlen(indent) - 2] = '\0';
    }
    return;
}

/**
 * construct_tournament_tree - constructs a tournament tree from a given array
 * @param a     the array
 * @param l     left bound of array
 * @param r     right bound of array
 */
NODE *construct_tournament_tree(int *a, int l, int r)
{
    NODE *node;
    int m;

    if (l > r) {
        return NULL;
    }

    node = (NODE *)malloc(sizeof(NODE));

    if (l == r) {
        node->n = a[l];
        node->left = node->right = NULL;
    }
    else {
        m = (l + r) >> 1;
        node->left = construct_tournament_tree(a, l, m);
        node->right = construct_tournament_tree(a, m + 1, r);
        node->n = node->left->n;
        if (node->n < node->right->n) {
            node->n = node->right->n;
        }
    }

    return node;
}

int main()
{
    int a[MAX_ELE + 1];
    int n;
    int i;
    NODE *tree;

    printf("Number of elements (max %d): ", MAX_ELE);
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    tree = construct_tournament_tree(a, 1, n);

    indent[0] = '\0';
    print_tree(tree, RIGHT, indent);

    return 0;
}
