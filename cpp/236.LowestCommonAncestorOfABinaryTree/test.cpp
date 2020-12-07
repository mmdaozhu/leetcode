/*
解体思路：
    递归

    1.如果root等于p或者q，则root是最近公共祖先。
    2.递归查找root->left和root->right。
    3.如果left为空，则root->right是最近公共祖先。
    4.如果left不为空，right为空，则root->left是最近公共祖先；
    5.如果两者都不为空，则root是最近公共祖先。

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
        if (root == p || root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        return left == nullptr ? right : right == nullptr ? left : root;
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
    TreeNode rootlrl(7);
    TreeNode rootlrr(4);
    TreeNode rootlr(2, &rootlrl, &rootlrr);

    TreeNode rootll(6);

    TreeNode rootl(5, &rootll, &rootlr);

    TreeNode rootrl(0);
    TreeNode rootrr(8);
    TreeNode rootr(1, &rootrl, &rootrr);

    TreeNode root(3, &rootl, &rootr);

    preOrder(&root);
    Solution s;
    assert(s.lowestCommonAncestor(&root, &rootl, &rootr) == &root);
}

void test2() {
    TreeNode rootlrl(7);
    TreeNode rootlrr(4);
    TreeNode rootlr(2, &rootlrl, &rootlrr);

    TreeNode rootll(6);

    TreeNode rootl(5, &rootll, &rootlr);

    TreeNode rootrl(0);
    TreeNode rootrr(8);
    TreeNode rootr(1, &rootrl, &rootrr);

    TreeNode root(3, &rootl, &rootr);

    preOrder(&root);
    Solution s;
    assert(s.lowestCommonAncestor(&root, &rootl, &rootlrr) == &rootl);
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