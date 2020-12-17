/*
解体思路：递归

时间复杂度分析：O(n)
*/

#include <algorithm>
#include <cassert>
#include <iostream>

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

void test1() {
    TreeNode rootRightLeft(15);
    TreeNode rootRightRight(7);
    TreeNode rootLeft(9);
    TreeNode rootRight(20, &rootRightLeft, &rootRightRight);
    TreeNode root(3, &rootLeft, &rootRight);
    Solution s;
    assert(s.minDepth(&root) == 2);
}

void test2() {
    TreeNode root6(6);
    TreeNode root5(5, nullptr, &root6);
    TreeNode root4(4, nullptr, &root5);
    TreeNode root3(3, nullptr, &root4);
    TreeNode root(2, nullptr, &root3);
    Solution s;
    assert(s.minDepth(&root) == 5);
}

int main() {
    test1();
    test2();
    return 0;
}
