typedef struct __TREE_NODE TREE_NODE;

struct __TREE_NODE {
    TREE_NODE *left;
    TREE_NODE *right;
};

typedef enum _DIRECION {
    LEFT = 0,
    RIGHT,
} DIRECTION;

typedef void (tu_node_visitor_t)(TREE_NODE *tree);

void tu_init();
void tu_print_tree(TREE_NODE *tree, DIRECTION dir, tu_node_visitor_t visit);

