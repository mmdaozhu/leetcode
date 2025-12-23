// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }

        if (min >= root->val || max <= root->val) {
            return false;
        }

        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

void test1() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    assert(s.isValidBST(root));
}

void test2() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    Solution s;
    assert(!s.isValidBST(root));
}

int main() {
    test1();
    test2();
    return 0;
}