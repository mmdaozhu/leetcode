#include <iostream>

/*
解题思路：
    递归

时间复杂度分析：O(n)
*/

/**
 * Definition for a binary tree node.
 *
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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void preOrder(const TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << std::endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    TreeNode root;
    root.val = 4;
    TreeNode rootLeft;
    rootLeft.val = 2;
    TreeNode rootRight;
    rootRight.val = 7;
    root.left = &rootLeft;
    root.right = &rootRight;
    preOrder(&root);

    Solution s;
    s.invertTree(&root);
    preOrder(&root);
    return 0;
}