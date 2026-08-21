/*
解题思路：
    递归
*/

// O(n)
// Runtime Beats 100.00%

// Definition for a binary tree node.
class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        Solution s = new Solution();
        assert s.maxDepth(root) == 3;
    }

    private static void test2() {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);

        Solution s = new Solution();
        assert s.maxDepth(root) == 2;
    }
}