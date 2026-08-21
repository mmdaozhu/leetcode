// O(n)
// Runtime Beats 100.00%

#include <cassert>
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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return Generate(nums, 0, nums.size() - 1);
    }

    TreeNode* Generate(std::vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Generate(nums, low, mid - 1);
        root->right = Generate(nums, mid + 1, high);
        return root;
    }
};

void test1() {
    std::vector<int> nums{-10, -3, 0, 5, 9};
    Solution s;
    TreeNode* root = s.sortedArrayToBST(nums);
    assert(root->val == 0);
    assert(root->left->val == -10);
    assert(root->left->right->val == -3);
    assert(root->right->val == 5);
    assert(root->right->right->val == 9);
}

void test2() {
    std::vector<int> nums = {1, 3};
    Solution s;
    TreeNode* root = s.sortedArrayToBST(nums);
    assert(root->val == 1);
    assert(root->right->val == 3);
}

int main() {
    test1();
    test2();
    return 0;
}