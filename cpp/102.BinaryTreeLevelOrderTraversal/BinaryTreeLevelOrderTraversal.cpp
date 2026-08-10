/*
解题思路：
    按层遍历
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> level;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

void test1() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    std::vector<std::vector<int>> expect{{3}, {9, 20}, {15, 7}};
    assert(s.levelOrder(root) == expect);
}

void test2() {
    TreeNode* root = new TreeNode(1);
    Solution s;
    std::vector<std::vector<int>> expect{{1}};
    assert(s.levelOrder(root) == expect);
}

void test3() {
    TreeNode* root = nullptr;
    Solution s;
    std::vector<std::vector<int>> expect;
    assert(s.levelOrder(root) == expect);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}