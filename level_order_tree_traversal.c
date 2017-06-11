/*
 * @file level_order_traversal.c
 * @author wangguibao (https://github.com/wangguibao/)
 * @brief level_order traversal of a binary tree
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

typedef struct _NODE_QUEUE {
    NODE **ele;

    int size;
    int begin;
    int end;
} NODE_QUEUE;

typedef enum {LEFT, RIGHT} DIRECTION;

char indent[(MAX_ELE + 1) * 2];
int top = 0;


int queue_init(NODE_QUEUE *queue, int size)
{
    queue->size = size;
    queue->begin = queue->end = 0;
    queue->ele = (NODE **)malloc(sizeof(NODE *) * size);
    if (queue->ele == NULL) {
        return -1;
    }

    return 0;
}

int queue_empty(NODE_QUEUE *queue)
{
    return (queue->begin == queue->end);
}

int queue_full(NODE_QUEUE *queue) {
    return (((queue->begin + 1) % queue->size) == queue->end);
}

int queue_in(NODE_QUEUE *queue, NODE *node)
{
    if (queue_full(queue)) {
        return -1;
    }

    queue->ele[queue->begin++] = node;

    return 0;
}

NODE *queue_out(NODE_QUEUE *queue)
{
    if (queue_empty(queue)) {
        return NULL;
    }

    NODE *node = queue->ele[queue->end];
    ++queue->end;
    return node;
}

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

void print_node(NODE *node)
{
    printf("%d ", node->a);
}
/*
 * _level_order_traverse_binary_tree
 * @param tree  root of the binary tree
 */
void _level_order_traverse_binary_tree(NODE *tree)
{
    top = 0;
    NODE_QUEUE queue;
    int ret = queue_init(&queue, MAX_ELE + 1);
    if (ret != 0) {
        return;
    }

    queue_in(&queue, tree);

    while (!queue_empty(&queue)) {
        NODE *node = queue_out(&queue);
        print_node(node);
        if (node->left != NULL) {
            queue_in(&queue, node->left);
        }
        if (node->right != NULL) {
            queue_in(&queue, node->right);
        }
    }

    return;
}

/*
 * level_order_traverse_binary_tree
 * Wrapper for _level_order_traverse_binary_tree
 */
void level_order_traverse_binary_tree(NODE *tree)
{
    printf("Recovered level order traversal: ");
    _level_order_traverse_binary_tree(tree);
    printf("\n");
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

    level_order_traverse_binary_tree(tree);

    return 0;
}
