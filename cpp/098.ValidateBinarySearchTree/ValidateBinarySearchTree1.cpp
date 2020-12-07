/*
解体思路：
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