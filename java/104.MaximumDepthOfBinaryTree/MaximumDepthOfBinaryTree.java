/*
解体思路：
    递归

时间复杂度分析：O(n)
*/

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    public static void main(String[] args) {
        test1();
    }

    private static void test1() {
        TreeNode rootRightLeft = new TreeNode(15);
        TreeNode rootRightRight = new TreeNode(7);
        TreeNode rootLeft = new TreeNode(9);
        TreeNode rootRight = new TreeNode(20, rootRightLeft, rootRightRight);
        TreeNode root = new TreeNode(3, rootLeft, rootRight);

        Solution s = new Solution();
        assert s.maxDepth(root) == 3;
    }
}