/*
解体思路：BFS

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <queue>

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

        std::queue<TreeNode *> queue;
        queue.push(root);

        auto depth = 0;
        while (!queue.empty()) {
            depth++;
            auto size = queue.size();
            for (int i = 0; i < size; i++) {
                if (queue.front()->left != nullptr) {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right != nullptr) {
                    queue.push(queue.front()->right);
                }
                queue.pop();
            }
        }
        return depth;
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
