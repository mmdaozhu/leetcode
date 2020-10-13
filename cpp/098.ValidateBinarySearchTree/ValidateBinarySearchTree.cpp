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
    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return inOrder(root);
    }

    bool inOrder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inOrder(root->left)) {
            return false;
        }

        if (prev != nullptr && prev->val >= root->val) {
            return false;
        }

        prev = root;
        return inOrder(root->right);
    }

private:
    TreeNode* prev;
};

void inOrder(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    std::cout << root->val << std::endl;
    inOrder(root->right);
}

int main() {
    TreeNode root;
    root.val = 2;
    TreeNode rootLeft;
    rootLeft.val = 1;
    TreeNode rootRight;
    rootRight.val = 3;
    root.left = &rootLeft;
    root.right = &rootRight;

    inOrder(&root);
    Solution s;
    assert(true == s.isValidBST(&root));
    return 0;
}