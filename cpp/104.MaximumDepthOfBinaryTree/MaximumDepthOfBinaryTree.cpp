/*
解题思路：
    广度优先遍历
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <queue>

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        int depth = 0;
        while (!queue.empty()) {
            depth++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                auto front = queue.front();
                if (front->left != nullptr) {
                    queue.push(front->left);
                }
                if (front->right != nullptr) {
                    queue.push(front->right);
                }
                queue.pop();
            }
        }
        return depth;
    }
};

void test1() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    assert(s.maxDepth(root) == 3);
}

void test2() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution s;
    assert(s.maxDepth(root) == 2);
}

int main() {
    test1();
    test2();
    return 0;
}