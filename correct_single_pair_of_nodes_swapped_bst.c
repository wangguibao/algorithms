/*
 * correct_single_pair_of_nodes_swapped_bst.c
 * Given a BST in which 2 nodes have their positions swapped, return the root
 * of corrected BST
 *
 * BONUS: print_tree() prints the binary tree prettily
 * BONUS: swap_nodes() swaps the positions of two nodes in a binary tree
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 16  /* Maximum number of nodes allowed */

typedef struct _NODE NODE;

struct _NODE {
    int a;
    NODE *left;
    NODE *right;
};

typedef enum {LEFT, RIGHT} DIRECTION;
typedef enum {TRUE, FALSE} BOOLEAN;

char indent[(MAX_ELE + 1) * 2];

/**
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

/**
 * print_node
 * Tree node accessor
 * @param node reference to tree node
 * @return N/A
 */
void print_node(NODE *node)
{
    printf("%d ", node->a);
}

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
        node->right = construct_binary_tree(&preorder[i + 1],
                                            &inorder[i + 1], n - (i + 1));

        return node;
    }
}

/**
 * find_left_max
 * Given a binary tree in which only two nodes have their positions swapped, find
 * the node which was swapped to left
 * @param  tree root of a subtree
 * @return node pointer to node holding max element, or the node which was
 *              swapped to left
 */
NODE *find_left_max(NODE *tree)
{
    NODE *left_max = NULL;
    NODE *right_max = NULL;
    NODE *max = tree;

    if (tree == NULL) {
        return NULL;
    }
    else if (tree->left != NULL) {
        left_max = find_left_max(tree->left);
        if (left_max != NULL && tree->a < left_max->a) {
            return left_max;
        }
    }

    if (tree->right != NULL) {
        right_max = find_left_max(tree->right);
        if (right_max != NULL && right_max->a > max->a) {
            max = right_max;
        }
    }

    return max;
}

/**
 * find_right_min
 * Given a binary tree in which only two nodes have their positions swapped, find
 * the node which was swapped to right
 * @param  tree root of a subtree
 * @return node pointer to node holding min element, or the node which was
 *              swapped to right
 */
NODE *find_right_min(NODE *tree)
{
    NODE *left_min = NULL;
    NODE *right_min = NULL;
    NODE *min = tree;

    if (tree == NULL) {
        return NULL;
    }
    else if (tree->right != NULL) {
        right_min = find_right_min(tree->right);
        if (right_min != NULL && tree->a > right_min->a) {
            return right_min;
        }
    }

    if (tree->left != NULL) {
        left_min = find_right_min(tree->left);
        if (left_min != NULL && left_min->a < min->a) {
            min = left_min;
        }
    }

    return min;
}

/**
 * find_parent
 * Given a pointer to a node in a binary tree, find the parent, or NULL if it's
 * the root
 * @param tree root of the binary tree
 * @param node a pointer to a node in binary tree
 * @return parent of the given node in the binary tree, or NULL if node is root
 */
NODE *find_parent(NODE *tree, NODE *node)
{
    NODE *prev = NULL;

    if (tree == NULL || node == NULL || node == tree) {
        return NULL;
    }

    if (node == tree->left || node == tree->right) {
        return tree;
    }

    if (tree->left != NULL) {
        prev = find_parent(tree->left, node);
    }
    if (prev == NULL && tree->right != NULL) {
        prev = find_parent(tree->right, node);
    }

    return prev;
}

/**
 * swap_nodes
 * swap two nodes in a binary tree
 * @param tree       root of the binary tree
 * @param left_node  pointer to left node
 * @param left_prev  pointer to parent of left node
 * @param right_node pointer to right node
 * @param right_prev pointer to parent of right node
 * @return           root of the new binary tree
 */
NODE *swap_nodes(NODE *tree, NODE *left_node, NODE *left_prev, NODE *right_node, NODE *right_prev)
{
    NODE *p;
    NODE *root = tree;

    if (left_node == NULL || right_node == NULL) {
        return tree;
    }

    if (left_prev == right_node) {                   /* right_node is parent of left_node */
        if (left_node == right_node->left) {
            p = left_node->left;
            left_node->left = right_node;
            right_node->left = p;

            p = left_node->right;
            left_node->right = right_node->right;
            right_node->right = p;
        }
        else {
            p = left_node->left;
            left_node->left = right_node->left;
            right_node->left = p;

            p = left_node->right;
            left_node->right = right_node;
            right_node->right = p;
        }

        if (right_prev != NULL) {
            if (right_node == right_prev->left) {
                right_prev->left = left_node;
            }
            else {
                right_prev->right = left_node;
            }
        }
    }
    else if (right_prev == left_node) {         /* left_node is parent of right_node */
        if (right_node == left_node->left) {
            p = right_node->left;
            right_node->left = left_node;
            left_node->left = p;

            p = right_node->right;
            right_node->right = left_node->right;
            left_node->right = p;
        }
        else {
            p = right_node->left;
            right_node->left = left_node->left;
            left_node->left = p;

            p = right_node->right;
            right_node->right = left_node;
            left_node->right = p;
        }

        if (left_prev != NULL) {
            if (left_node == left_prev->left) {
                left_prev->left = right_node;
            }
            else {
                left_prev->right = right_node;
            }
        }
    }
    else {                                      /* Random nodes */
        p = left_node->left;
        left_node->left = right_node->left;
        right_node->left = p;

        p = left_node->right;
        left_node->right = right_node->right;
        right_node->right = p;

        if (left_prev != NULL) {
            if (left_node == left_prev->left) {
                left_prev->left = right_node;
            }
            else {
                left_prev->right = right_node;
            }
        }

        if (right_prev != NULL) {
            if (right_node == right_prev->left) {
                right_prev->left = left_node;
            }
            else {
                right_prev->right = left_node;
            }
        }
    }

    if (left_prev == NULL) {
        root = right_node;
    }
    else if (right_prev == NULL) {
        root = left_node;
    }

    return root;
}

/**
 * correct_bst
 * Given a BST in which only two nodes have their positions swapped, corrects
 * the two nodes and returns root of corrected BST
 * @param  tree root of the BST in which two nodes have their positions swapped
 * @return root of corrected BST
 */
NODE *correct_bst(NODE *tree)
{
    NODE *left_node = find_left_max(tree);
    NODE *right_node = find_right_min(tree);
    NODE *left_prev = NULL;
    NODE *right_prev = NULL;

    if (left_node == NULL) {
        printf("Left half not found\n");
        return NULL;
    }
    else if (right_node == NULL) {
        printf("Right half not found\n");
        return NULL;
    }

    left_prev = find_parent(tree, left_node);
    right_prev = find_parent(tree, right_node);

    tree = swap_nodes(tree, left_node, left_prev, right_node, right_prev);

    return tree;
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
    print_tree(tree, RIGHT, indent);

    tree = correct_bst(tree);
    indent[0] = '\0';
    print_tree(tree, RIGHT, indent);

    return 0;
}

