/*
解题思路：
    深度优先遍历
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        max_depth = 0;
        maxDepth(root, 0);
        return max_depth;
    }

    void maxDepth(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        level++;
        if (max_depth < level) {
            max_depth = level;
        }
        maxDepth(root->left, level);
        maxDepth(root->right, level);
    }

private:
    int max_depth{};
};

void test1() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    assert(s.maxDepth(root) == 3);
}

void test2() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution s;
    assert(s.maxDepth(root) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}