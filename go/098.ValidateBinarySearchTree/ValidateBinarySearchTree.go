// O(n)
// Runtime Beats 100.00%

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var pre *TreeNode = nil

func isValidBST(root *TreeNode) bool {
	pre = nil
	return inOrder(root)
}

func inOrder(root *TreeNode) bool {
	if root == nil {
		return true
	}

	if !inOrder(root.Left) {
		return false
	}

	if pre != nil && pre.Val >= root.Val {
		return false
	}
	pre = root
	return inOrder(root.Right)
}
