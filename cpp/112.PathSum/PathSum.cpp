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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int path = 0;
        return EvalPath(root, path, sum);
    }

private:
    bool EvalPath(TreeNode* root, int path, int sum) {
        if (root == nullptr) {
            return false;
        }

        path += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (path == sum) {
                return true;
            } else {
                return false;
            }
        }

        if (EvalPath(root->left, path, sum)) {
            return true;
        }
        if (EvalPath(root->right, path, sum)) {
            return true;
        }
        return false;
    }
};

int main() {
    TreeNode root;
    root.val = 2;
    TreeNode rootLeft;
    rootLeft.val = 1;
    TreeNode rootRight;
    rootRight.val = 3;
    root.left = &rootLeft;
    root.right = &rootRight;
    Solution s;
    assert(true == s.hasPathSum(&root, 5));
    return 0;
}