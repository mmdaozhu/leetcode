/*
解题思路：
    动态规划
    dp[n] = 用 n 个节点能组成的 BST 数量
    左子树有 dp[i-1] 种
    右子树有 dp[n-i] 种
*/

// Runtime Beats 30.46%

#include <cassert>
#include <cstddef>
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
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }

    std::vector<TreeNode*> generate(int start, int end) {
        std::vector<TreeNode*> results;
        if (start > end) {
            return {nullptr};
        }
        for (int i = start; i <= end; i++) {
            auto lefts = generate(start, i - 1);
            auto rights = generate(i + 1, end);

            for (auto l : lefts) {
                for (auto r : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};

void test1() {
    std::vector<TreeNode*> results{new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3))),
                                   new TreeNode(1, nullptr, new TreeNode(3, new TreeNode(2), nullptr)),
                                   new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                                   new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr),
                                   new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), nullptr)};
    Solution s;
    assert(s.generateTrees(3) == results);
}

void test2() {
    std::vector<TreeNode*> results{new TreeNode(1)};
    Solution s;
    assert(s.generateTrees(1) == results);
}

int main() {
    test1();
    test2();
    return 0;
}