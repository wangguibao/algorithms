/*
 * vertical-sum-of-binary-tree.c
 *
 * [http://stackoverflow.com/questions/14485255/vertical-sum-in-a-given-binary-tree]
 *
 * Given a Binary Tree, find vertical sum of the nodes that are in same vertical
 * line. Print all sums through different vertical lines.
 *
 * To understand what's same vertical line, we need to define horizontal
 * distances first. If two nodes have the same Horizontal Distance (HD), then
 * they are on same vertical line. The idea of HD is simple. HD for root is 0,
 * a right edge (edge connecting to right subtree) is considered as +1
 * horizontal distance and a left edge is considered as -1 horizontal distance.
 *
 * For example, in the above tree, HD for Node 4 is at -2, HD for Node 2 is -1,
 * HD for 5 and 6 is 0 and HD for node 7 is +2.
 *
 * Examples:
 *
 *      1
 *    /   \
 *   2     3
 *  / \   / \
 *  4  5  6  7
 * The tree has 5 vertical lines
 * Vertical-Line-1 has only one node 4 => vertical sum is 4
 * Vertical-Line-2: has only one node 2=> vertical sum is 2
 * Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
 * Vertical-Line-4: has only one node 3 => vertical sum is 3
 * Vertical-Line-5: has only one node 7 => vertical sum is 7
 * So expected output is 4, 2, 12, 3 and 7
 *
 * Solution: [http://stackoverflow.com/a/16176329/1513460]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 16
#define MAX_HD  16      /* Max horizontal distance */

typedef struct _NODE NODE;

struct _NODE {
    int a;
    NODE *left;
    NODE *right;
};

int sums[MAX_HD + 1] = {0, };   /* Sums of each vertical line */
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
    node->a = a;
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
 * vertical-sum
 * Prints vertical sums of nodes in the same vertical lines
 * @param tree  root of the binary tree
 * @param hd    horizontal distance
 */
void vertical_sums(NODE *tree, int hd)
{
    /**
     * By definition horizontal distance ranges [-MAX_HD/2, MAX_HD/2]
     * We shift this range by MAX_HD/2, to ease array access
     */
    int index = hd + MAX_HD / 2;

    if (tree == NULL) {
        return;
    }

    sums[index] += tree->a;

    if (tree->left != NULL) {
        vertical_sums(tree->left, hd - 1);
    }
    if (tree->right != NULL) {
        vertical_sums(tree->right, hd + 1);
    }
}

int main()
{
    int preorder[MAX_ELE + 1];
    int inorder[MAX_ELE + 1];
    int n;
    int i;
    NODE *tree;

    printf("Number of elements: ");
    scanf("%d", &n);

    printf("Preorder sequence (max 16): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Inorder sequence (max 16): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    tree = construct_binary_tree(preorder, inorder, n);
    vertical_sums(tree, 0);

    printf("Sums: ");
    for (i = 0; i < MAX_HD; i++) {
        printf(" %d", sums[i]);
    }
    printf("\n");
    return 0;
}
