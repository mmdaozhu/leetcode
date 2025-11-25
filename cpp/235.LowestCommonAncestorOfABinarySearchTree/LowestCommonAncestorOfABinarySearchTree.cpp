/*
解题思路：
    递归

    1.如果p和q的值都小于root，递归查找root->left。
    2.如果p和q的值都大于root，递归查找root->right.
    3.如果上述条件都不满足，则返回root。

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

void preOrder(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void test1() {
    TreeNode rootlrl(3);
    TreeNode rootlrr(5);
    TreeNode rootlr(4, &rootlrl, &rootlrr);

    TreeNode rootll(0);

    TreeNode rootl(2, &rootll, &rootlr);

    TreeNode rootrl(7);
    TreeNode rootrr(9);
    TreeNode rootr(8, &rootrl, &rootrr);

    TreeNode root(6, &rootl, &rootr);

    preOrder(&root);
    Solution s;
    assert(s.lowestCommonAncestor(&root, &rootl, &rootr) == &root);
}

void test2() {
    TreeNode rootlrl(3);
    TreeNode rootlrr(5);
    TreeNode rootlr(4, &rootlrl, &rootlrr);

    TreeNode rootll(0);

    TreeNode rootl(2, &rootll, &rootlr);

    TreeNode rootrl(7);
    TreeNode rootrr(9);
    TreeNode rootr(8, &rootrl, &rootrr);

    TreeNode root(6, &rootl, &rootr);

    preOrder(&root);
    Solution s;
    assert(s.lowestCommonAncestor(&root, &rootl, &rootlr) == &rootl);
}

void test3() {
    TreeNode rootl(2);
    TreeNode root(1, &rootl, nullptr);

    preOrder(&root);
    Solution s;
    assert(s.lowestCommonAncestor(&root, &root, &rootl) == &root);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}