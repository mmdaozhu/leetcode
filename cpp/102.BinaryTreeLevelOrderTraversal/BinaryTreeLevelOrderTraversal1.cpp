/*
解题思路：按层遍历

时间复杂度分析：O(n)
*/

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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode *> queue;

        queue.push(root);
        while (!queue.empty()) {
            std::vector<int> level;
            auto size = queue.size();
            for (int i = 0; i < size; i++) {
                level.emplace_back(queue.front()->val);
                if (queue.front()->left != nullptr) {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right != nullptr) {
                    queue.push(queue.front()->right);
                }
                queue.pop();
            }
            result.emplace_back(level);
        }
        return result;
    }
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