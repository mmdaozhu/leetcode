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
    void recoverTree(TreeNode* root) {
        InOrder(root);
        std::swap(first->val, second->val);
    }

    void InOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        InOrder(root->left);

        if (prev && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }

        prev = root;

        InOrder(root->right);
    }

private:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
};

void test1() {
    TreeNode* root = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
    Solution s;
    s.recoverTree(root);
    assert(root->val == 3 && root->left->val == 1 && root->left->right->val == 2);
}

void test2() {
    TreeNode* root = new TreeNode(3, new TreeNode(1, nullptr, nullptr), new TreeNode(4, new TreeNode(2), nullptr));
    Solution s;
    s.recoverTree(root);
    assert(root->val == 2 && root->left->val == 1 && root->right->val == 4 && root->right->left->val == 3);
}

int main() {
    test1();
    test2();
    return 0;
}