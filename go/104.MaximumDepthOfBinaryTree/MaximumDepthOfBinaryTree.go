// O(n)
// Runtime Beats 6.44%

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if nil == root {
		return 0
	}
	left := maxDepth(root.Left)
	right := maxDepth(root.Right)
	if left < right {
		return right + 1
	} else {
		return left + 1
	}
}