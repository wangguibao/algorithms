/*
 * tree-from-preorder-inorder-sequence.c
 * Create a binary tree from preorder and inorder traversal sequence
 *
 * BONUS: print_tree() prints the binary tree prettily
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 16

typedef struct _NODE NODE;

struct _NODE {
    int a;
    NODE *left;
    NODE *right;
};

typedef enum {LEFT, RIGHT} DIRECTION;

char indent[(MAX_ELE + 1) * 2];

/*
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
        printf("%d\n", tree->a);

        print_tree(tree->left, LEFT, indent);
        print_tree(tree->right, RIGHT, indent);
        indent[strlen(indent) - 2] = '\0';
    }
    return;
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
    indent[0] = '\0';
    print_tree(tree, RIGHT, indent);

    return 0;
}
