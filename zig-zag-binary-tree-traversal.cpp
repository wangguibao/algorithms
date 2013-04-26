/*
 * zig-zag-binary-tree.cpp
 * Create a binary tree from preorder and inorder traversal sequence, then print
 * it out in zig-zag order, using two stacks
 *
 * Origin: http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
 * BONUS: print_tree() prints the binary tree structurally
 */
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int max_ele = 16;
typedef struct _NODE NODE;
struct _NODE {
    int a;
    NODE *left;
    NODE *right;
};
typedef enum {LEFT, RIGHT} DIRECTION;
char indent[(max_ele + 1) * 2];
stack<NODE *> st_zig;
stack<NODE *> st_zag;

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
    NODE *node = new NODE;
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
        cout << indent;

        if (dir == LEFT) {
            cout << "|-";
            strcat(indent, "| ");
        }
        else {
            cout << "\\-";
            strcat(indent, "  ");
        }
        cout << tree->a << endl;

        print_tree(tree->left, LEFT, indent);
        print_tree(tree->right, RIGHT, indent);
        indent[strlen(indent) - 2] = '\0';
    }
    return;
}

/*
 * zig_zag_traversal
 * Print out a binary tree in zig-zag manner
 * @param tree  Root of the tree
 */
void zig_zag_traversal(NODE *tree)
{
    DIRECTION d = RIGHT;                                // Direction
    if (tree == NULL) {
        return;
    }

    st_zig.push(tree);
    while (st_zig.empty() == false || st_zag.empty() == false) {
        if (d == RIGHT) {
            while (st_zig.empty() == false) {
                NODE *node = st_zig.top();
                cout << node->a << " ";
                if (node->right != NULL) {
                    st_zag.push(node->right);
                }
                if (node->left != NULL) {
                    st_zag.push(node->left);
                }
                st_zig.pop();
            }
            cout << endl;
            d = LEFT;
        }
        else if (d == LEFT) {
            while (st_zag.empty() == false) {
                NODE *node = st_zag.top();
                cout << node->a << " ";
                if (node->left != NULL) {
                    st_zig.push(node->left);
                }
                if (node->right != NULL) {
                    st_zig.push(node->right);
                }
                st_zag.pop();
            }
            cout << endl;
            d = RIGHT;
        }
    }

    return;
}
int main()
{
    int preorder[max_ele + 1];
    int inorder[max_ele + 1];
    int n;
    int i;
    NODE *tree;

    cout << "Number of elements: ";
    cin >> n;

    cout << "Preorder sequence (max 16): ";
    for (i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    cout << "Inorder sequence (max 16): ";
    for (i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    tree = construct_binary_tree(preorder, inorder, n);
    indent[0] = '\0';
    print_tree(tree, RIGHT, indent);

    zig_zag_traversal(tree);
    return 0;
}
