#include <stdio.h>
#include <string.h>
#include "treeutil.h"

#define MAX_LEN 32
static char indent[(MAX_LEN + 1) * 2];

void tu_init()
{
    indent[0] = '\0';
}

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

