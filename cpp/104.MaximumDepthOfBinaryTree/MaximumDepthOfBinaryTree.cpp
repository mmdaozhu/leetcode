#include <cassert>
#include <iostream>

/*
解体思路：
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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // reduce recursion times.
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
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
    root.val = 3;
    TreeNode rootLeft;
    rootLeft.val = 9;
    TreeNode rootRight;
    rootRight.val = 20;
    root.left = &rootLeft;
    root.right = &rootRight;
    TreeNode rootRightLeft;
    rootRightLeft.val = 15;
    TreeNode rootRightRight;
    rootRightRight.val = 7;
    rootRight.left = &rootRightLeft;
    rootRight.right = &rootRightRight;

    preOrder(&root);
    Solution s;
    assert(3 == s.maxDepth(&root));
    return 0;
}