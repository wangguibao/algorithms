/*
 * tarjan-offline-lca.c: Tarjan's offline Least Common Ancestor problem
 * Problem 21-3 of 2e of Introduction to Algorithms, 2001 MIT
 */
#include <stdio.h>

#define MAX_NODES   32
#define MAX_PAIRS   32

typedef struct _NODE {
    int v;
    struct _NODE *left_child;
    struct _NODE *right_sibling;
} NODE;

typedef enum _COLOR {
    WHITE = 1,
    BLACK = 2,
} COLOR;

int ancestor[MAX_NODES + 1] = {0, };    /* To hold node k's ancestor */

/* Data used in left-child-right-sibling tree */
int left_child[MAX_NODES + 1] = {0};    /* To hold node k's left child */
int right_sibling[MAX_NODES + 1] = {0,};/* To hold node k's right sibling */
COLOR color[MAX_NODES + 1] = {0,};      /* To hold node k's color */

/* Data used in disjoint sets */
int rank[MAX_NODES + 1] = {0,};         /* To hold node k's rank */
int parent[MAX_NODES + 1] = {0,};       /* To hold node k's parent */

/* To hold node-pairs */
int pair_left[MAX_PAIRS + 1] = {0,};    /* left node of the node-pair */
int pair_right[MAX_PAIRS + 1] = {0,};   /* right node of the node-pair */
int npair = 0;

void make_set(int k)
{
    if (k < 1 || k > MAX_NODES) {
        return;
    }

    color[k] = WHITE;
    parent[k] = k;
    rank[k] = 0;

    return;
}

void link(int u, int v)
{
    if (rank[u]> rank[v]) {
        parent[v] = u;
    }
    else {
        parent[u] = v;
        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }

    return;
}

int find_set(int k)
{
    if (parent[k] != k) {
        parent[k] = find_set(parent[k]);
    }
    return parent[k];
}

void union_set(int u, int v)
{
    link(find_set(u), find_set(v));
}

void lca(int u)
{
    int child;
    int i;

    make_set(u);
    ancestor[find_set(u)] = u;

    child = left_child[u];
    while (child != 0) {
        lca(child);
        union_set(u, child);
        ancestor[find_set(u)] = u;

        child = right_sibling[child];
    }

    color[u] = BLACK;
    for (i = 1; i <= npair; i++) {
        if (pair_left[i] == u) {
            if (color[pair_right[i]] == BLACK) {
                printf("(%d %d) -> %d\n",
                       pair_left[i],
                       pair_right[i],
                       ancestor[find_set(pair_right[i])]);
            }
        }
        else if (pair_right[i] == u) {
            if (color[pair_left[i]] == BLACK) {
                printf("(%d %d) -> %d\n",
                       pair_left[i],
                       pair_right[i],
                       ancestor[find_set(pair_left[i])]);
            }
        }
    }

    return;
}

int make_tree()
{
    int root;
    int parent;
    int v;
    int n;
    int i;
    int lchild;
    int rsibling;

    printf("Input number of nodes (maximum %d):\n", MAX_NODES);
    scanf("%d", &n);
    n = n > MAX_NODES ? MAX_NODES : n;

    printf("Input tree structure in tree level order now.\n");
    printf("In the following %d lines, in each line input 2 numbers, "
           "first is node value, second is node parent\n", n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d", &v, &parent);
        if (v == parent) {
            root = v;
            continue;
        }
        lchild = left_child[parent];
        if (lchild == 0) {      /* Parent has no children yet */
            left_child[parent] = v;
        }
        else {
            rsibling = lchild;
            while (right_sibling[rsibling] != 0) {
                rsibling = right_sibling[rsibling];
            }
            right_sibling[rsibling] = v;
        }
    }

    return root;
}

int main()
{
    int tree = make_tree();
    int i;
    int left_node;
    int right_node;

    printf("Number of node pairs:");
    scanf ("%d", &npair);

    printf("Input %d node pairs, one pair each line:\n", npair);
    for (i = 1; i <= npair; i++) {
        scanf("%d %d", &left_node, &right_node);
        pair_left[i] = left_node;
        pair_right[i] = right_node;
    }

    lca(tree);

    return 0;
}
