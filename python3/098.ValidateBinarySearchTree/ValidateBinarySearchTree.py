# O(n)
# Runtime Beats 100.00%

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        self.prev = None
        return self.inOrder(root)

    def inOrder(self,root:TreeNode) -> bool:
        if root is None:
            return True
        if not self.inOrder(root.left):
            return False
        if self.prev and self.prev.val >= root.val:
            return False
        self.prev = root
        return self.inOrder(root.right)