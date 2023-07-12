def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    if root is None: return None
    if root.val == val:
        return root
    elif root.val > val:
        if root.left:
            return self.searchBST(root.left, val)
        else:
            return None
    elif root.val < val:
        if root.right:
            return self.searchBST(root.right, val)
        else:
            return None