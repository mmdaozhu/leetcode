/*
解题思路：
    对于当前节点，如果它有左子树，找到左子树最右边的节点，连接当前节点的右节点。
    当前节点的右节点指向左节点，左节点指向空
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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* process = root;
        while (process) {
            if (process->left) {
                TreeNode* p = process->left;
                while (p->right) {
                    p = p->right;
                }
                p->right = process->right;
                process->right = process->left;
                process->left = nullptr;
            }
            process = process->right;
        }
    }
};

void test1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution s;
    s.flatten(root);
    assert(root->val == 1);
    assert(root->right->val == 2);
    assert(root->right->right->val == 3);
    assert(root->right->right->right->val == 4);
    assert(root->right->right->right->right->val == 5);
    assert(root->right->right->right->right->right->val == 6);
}

void test2() {
    TreeNode* root = nullptr;
    Solution s;
    s.flatten(root);
    assert(root == nullptr);
}

void test3() {
    TreeNode* root = new TreeNode(0);
    Solution s;
    s.flatten(root);
    assert(root->val == 0);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}