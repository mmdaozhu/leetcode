/*
解题思路：深度优先遍历

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return result;
        }
        auto level = 0;
        preOrder(root, level);
        return result;
    }

    void preOrder(TreeNode *root, int level) {
        if (result.size() < level + 1) {
            std::vector<int> temp;
            result.emplace_back(temp);
        }
        result[level].emplace_back(root->val);

        if (root->left != nullptr) {
            preOrder(root->left, level + 1);
        }
        if (root->right != nullptr) {
            preOrder(root->right, level + 1);
        }
    }

private:
    std::vector<std::vector<int>> result;
};

void test1() {
    TreeNode rootRightLeft(15);
    TreeNode rootRightRight(7);
    TreeNode rootRight(20, &rootRightLeft, &rootRightRight);
    TreeNode rootLeft(9);
    TreeNode root(3, &rootLeft, &rootRight);

    std::vector<std::vector<int>> result{{3}, {9, 20}, {15, 7}};
    Solution s;
    assert(s.levelOrder(&root) == result);
}

int main() {
    test1();
    return 0;
}