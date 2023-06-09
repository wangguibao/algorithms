/**
 * @file leetcode108_convert_sorted_array_to_binary_search_tree.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/06/07 22:40
 * @brief https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *
 **/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        size_t len = nums.size();
        int b = 0;
        int e = len - 1;

        return buildTree(nums, b, e);
    }

private:
    TreeNode* buildTree(std::vector<int>& nums, int b, int e) {
        if (b > e) {
            return nullptr;
        }

        int mid = (b + e) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, b, mid - 1);
        node->right = buildTree(nums, mid + 1, e);
        return node;
    }
};

void printTree(TreeNode* root) {
    std::queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    std::cout << std::endl;
}

int main() {
    while (1) {
        std::cout << "Number of elements in the array (Ctrl-C to exit): " << std::endl;
        int n;
        if (!(std::cin >> n)) {
            return 0;
        }

        std::cout << n << " integers:" << std::endl;

        std::vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            nums.emplace_back(x);
        }

        Solution solution;
        auto ret = solution.sortedArrayToBST(nums);

        printTree(ret);
    }
    return 0;
}
