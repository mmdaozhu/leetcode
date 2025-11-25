/*
解题思路：
    递归

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int* min = nullptr;
        int* max = nullptr;
        return isValidBST(root, min, max);
    }

    bool isValidBST(TreeNode* root, int* min, int* max) {
        if (root == nullptr) {
            return true;
        }
        if (min != nullptr && root->val <= *min) {
            return false;
        }

        if (max != nullptr && root->val >= *max) {
            return false;
        }

        return isValidBST(root->left, min, &root->val) && isValidBST(root->right, &root->val, max);
    }
};

void inOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    std::cout << root->val << std::endl;
    inOrder(root->right);
}

void test1() {
    TreeNode rootLeft(1);
    TreeNode rootRight(3);
    TreeNode root(2, &rootLeft, &rootRight);
    inOrder(&root);
    Solution s;
    assert(s.isValidBST(&root) == true);
}

void test2() {
    TreeNode rootRightLeft(3);
    TreeNode rootRightRight(6);
    TreeNode rootRight(4, &rootRightLeft, &rootRightRight);
    TreeNode rootLeft(1);
    TreeNode root(5, &rootLeft, &rootRight);
    inOrder(&root);
    Solution s;
    assert(s.isValidBST(&root) == false);
}

int main() {
    test1();
    test2();
    return 0;
}