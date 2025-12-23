// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode* root) {
        results.clear();
        inorder(root);
        return results;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);
        results.push_back(root->val);
        inorder(root->right);
    }

private:
    std::vector<int> results;
};

void test1() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    std::vector<int> expect{1, 3, 2};
    assert(s.inorderTraversal(root) == expect);
}

void test2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    Solution s;
    std::vector<int> expect{4, 2, 6, 5, 7, 1, 3, 9, 8};
    assert(s.inorderTraversal(root) == expect);
}

void test3() {
    TreeNode* root = nullptr;

    Solution s;
    std::vector<int> expect;
    assert(s.inorderTraversal(root) == expect);
}

void test4() {
    TreeNode* root = new TreeNode(1);

    Solution s;
    std::vector<int> expect{1};
    assert(s.inorderTraversal(root) == expect);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}