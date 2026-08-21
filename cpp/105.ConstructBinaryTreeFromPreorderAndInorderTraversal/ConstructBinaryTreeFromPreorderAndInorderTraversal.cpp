// O(n)
// Runtime Beats 53.29%

#include <cassert>
#include <iostream>
#include <unordered_map>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return Generate(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* Generate(std::vector<int>& preorder, int pre_low, int pre_high, std::vector<int>& inorder, int in_low,
                       int in_high) {
        if (pre_low > pre_high || in_low > in_high) {
            return nullptr;
        }
        int root_val = preorder[pre_low];
        int root_pos = pos[root_val];
        int left_size = root_pos - in_low;

        TreeNode* root = new TreeNode(root_val);
        root->left = Generate(preorder, pre_low + 1, pre_low + left_size, inorder, in_low, root_pos - 1);
        root->right = Generate(preorder, pre_low + left_size + 1, pre_high, inorder, root_pos + 1, in_high);
        return root;
    }

private:
    std::unordered_map<int, int> pos;
};

void test1() {
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    assert(root->val == 3);
    assert(root->left->val == 9);
    assert(root->right->val == 20);
    assert(root->right->left->val == 15);
    assert(root->right->right->val == 7);
}

void test2() {
    std::vector<int> preorder = {-1};
    std::vector<int> inorder = {-1};
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    assert(root->val == -1);
}

int main() {
    test1();
    test2();
    return 0;
}