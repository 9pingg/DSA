"""
Complexity of finding node is O(h) So, overall complexity is O(h). 
Space complexity is O(h) as well, because we use recursion and potentially we can find our node in the bottom of tree.
"""

def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    res = root
    if root is None: return TreeNode(val)
    if root.val > val:
        if root.left:
            self.insertIntoBST(root.left, val)
        else:
            root.left = TreeNode(val)
    if root.val < val:
        if root.right:
            self.insertIntoBST(root.right, val)
        else:
            root.right = TreeNode(val)
    return res