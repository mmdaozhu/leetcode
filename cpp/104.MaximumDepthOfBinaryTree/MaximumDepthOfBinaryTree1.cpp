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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

void test1() {
    TreeNode rootRightLeft(15);
    TreeNode rootRightRight(7);
    TreeNode rootLeft(9);
    TreeNode rootRight(20, &rootRightLeft, &rootRightRight);
    TreeNode root(3, &rootLeft, &rootRight);
    Solution s;
    assert(s.maxDepth(&root) == 3);
}

int main() {
    test1();
    return 0;
}
