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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

void test1() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    Solution s;
    assert(s.isSameTree(p, q));
}

void test2() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);
    Solution s;
    assert(!s.isSameTree(p, q));
}

void test3() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    Solution s;
    assert(!s.isSameTree(p, q));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}