/*
 * binary_tree_least_common_ancestor.c - find least common ancestor of two nodes in a binary tree
 *
 * Author: Wang Guibao <wang_guibao#163.com>
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELE     32

typedef struct _NODE NODE;
struct _NODE {
    NODE *left;
    NODE *right;
    int n;
};

/**
 * construct_binary_tree
 * Constructs binary tree from preorder and inorder traversal sequence
 * @param preorder  preorder traversal sequence
 * @param inorder   inorder traversal sequence
 * @return root of the binary tree
 */
NODE *construct_binary_tree(int *preorder, int *inorder, int n)
{
    int a;
    int i;

    if (n <= 0) {
        return NULL;
    }

    a = preorder[0];
    NODE *node = malloc(sizeof(NODE));
    node->n = a;
    node->left = NULL;
    node->right = NULL;

    if (n == 1) {
        return node;
    }
    else {
        for (i = 0; i < n; i++) {
            if (inorder[i] == a) {
                break;
            }
        }
        node->left = construct_binary_tree(&preorder[1], inorder, i);
        node->right = construct_binary_tree(&preorder[i + 1], &inorder[i + 1], n - (i + 1));

        return node;
    }
}

/**
 * least_common_ancestor
 * Find least common ancestor of two nodes in a binary tree.
 * For the seek of simplicity, assume all elements in the tree are distinct
 *
 * @param tree  the binary tree
 * @param a     the first node value
 * @param b     the second node value
 * @return the node of the least common ancestor, otherwise return INFINITY
 */
NODE *least_common_ancestor(NODE *tree, int a, int b)
{
    NODE *left;
    NODE *right;

    if (tree == NULL) {
        return NULL;
    }

    left = least_common_ancestor(tree->left, a, b);
    right = least_common_ancestor(tree->right, a, b);

    if (left != NULL && right != NULL) {
        return tree;
    }
    else if ((left != NULL || right != NULL) && (tree->n == a || tree->n == b)) {
        return tree;
    }
    else if (tree->n == a || tree->n == b) {
        return tree;
    }
    else if (left != NULL) {
        return left;
    }
    else if (right != NULL) {
        return right;
    }
    else {
        return NULL;
    }
}

int main()
{
    int preorder[MAX_ELE + 1];
    int inorder[MAX_ELE + 1];
    int n;
    int a;                                      /* first node value to find */
    int b;                                      /* second node value to find */
    int i;
    NODE *tree;
    NODE *lca;

    printf("Number of elements: ");
    scanf("%d", &n);

    printf("Preorder sequence (max %d, delimit with space): ", MAX_ELE);
    for (i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Inorder sequence (max %d, delimit with space): ", MAX_ELE);
    for (i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    tree = construct_binary_tree(preorder, inorder, n);

    printf("Two value in tree (delimit with space): ");
    scanf("%d %d", &a, &b);

    lca = least_common_ancestor(tree, a, b);
    if (lca != NULL) {
        printf("%d", lca->n);
    }
    else {
        printf("Find fail!\n");
    }

    return 0;
}
