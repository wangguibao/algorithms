/*
 * threaded-binary-tree.c
 * Create a binary tree from preorder and inorder traversal sequence, then right thread it
 *
 * BONUS: print_tree() prints the binary tree prettily
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 16

typedef struct _NODE NODE;
typedef enum {LEFT, RIGHT} DIRECTION;
typedef enum {LINK, THREAD} FLAG;

struct _NODE {
    int a;
    FLAG lflag;
    FLAG rflag;
    NODE *left;
    NODE *right;
};

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
    node->lflag = LINK;
    node->right = NULL;
    node->rflag = LINK;

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


/*
 * thread_binary_tree
 * Thread a binary tree
 * @param tree  root of the binary tree
 */
void right_thread_binary_tree(NODE *tree, NODE *prev)
{
    if (tree == NULL) {
        return;
    }

    if (tree->left != NULL && tree->lflag == LINK) {
        right_thread_binary_tree(tree->left, tree);
    }

    if (tree->right != NULL && tree->rflag == LINK) {
        right_thread_binary_tree(tree->right, prev);
    }
    else {
        tree->rflag = THREAD;
        tree->right = prev;
    }
}

void traverse_node(NODE *node)
{
    if (node != NULL && node->rflag == THREAD) {
        printf("%d right thread %d\n", node->a, node->right->a);
    }
}
/*
 * _inorder_traverse_binary_tree
 * @param tree  root of the binary tree
 */
void _inorder_traverse_binary_tree(NODE *tree, void fn(NODE *node))
{
    NODE *node = tree;

    if (tree == NULL) {
        return;
    }

    if (node->left != NULL && node->lflag == LINK) {
        _inorder_traverse_binary_tree(node->left, fn);
    }

    fn(node);

    if (node->right != NULL && node->rflag == LINK) {
        _inorder_traverse_binary_tree(node->right, fn);
    }
}

/*
 * inorder_traverse_binary_tree
 * Wrapper for _inorder_traverse_binary_tree
 */
void inorder_traverse_binary_tree(NODE *tree, void fn(NODE *node))
{
    printf("Right threads: \n");
    _inorder_traverse_binary_tree(tree, fn);
    printf("\n");
}

int main()
{
    int preorder[MAX_ELE + 1];
    int inorder[MAX_ELE + 1];
    int n;
    int i;
    NODE *tree;
    NODE *prev;

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

    prev = tree;
    right_thread_binary_tree(tree, prev);
    inorder_traverse_binary_tree(tree, traverse_node);

    return 0;
}
