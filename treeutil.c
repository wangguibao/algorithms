/*
 * treeutil.c - tree utilities library
 * Author: Wang Guibao <wang_guibao#163.com>
 */
#include <stdio.h>
#include <string.h>
#include "treeutil.h"

#define MAX_LEN 32
static char indent[(MAX_LEN + 1) * 2];

/**
 * tu_init
 * Initialization work for treeutil library.
 * This function should be called before other functions in this library
 */
void tu_init()
{
    indent[0] = '\0';
}

/**
 * tu_print_tree
 *
 * Graphically print out binary tree
 *
 * NOTE: 1) Call tu_init() before calling this function
 *       2) First part of application tree nodes should have the same structure as that TREE_NODE
 *          so that type cast won't harm you (and your device)
 * Use:
 *     // assuming root points to root of the binary tree and below visit function
 *     // void tree_visit(NODE *node);
 *     tu_print_tree(ROOT, RIGHT, visit)
 *
 * @param tree  root to the tree
 * @param dir   tree traversal direction
 * @param visit node visit function pointer
 */
void tu_print_tree(TREE_NODE *tree, DIRECTION dir, tu_node_visitor_t visit)
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

        visit(tree);

        tu_print_tree(tree->left, LEFT, visit);
        tu_print_tree(tree->right, RIGHT, visit);
        indent[strlen(indent) - 2] = '\0';
    }
    return;
}
