def flatten(self, root: Optional[TreeNode]) -> None:
    """
    Do not return anything, modify root in-place instead.
    """
    # try to think of a basic soln, a tree with 3 nodes
    def preorder(root):
        if root is None: return
        preorder(root.left)
        preorder(root.right)
        # if left node exists we remove it and add it on root.right, 
        # then then the root.right node will be added after this node
        if root.left: 
            r = root.right
            root.right = root.left
            # traverse till reach last node of new added l
            l = root.right
            while l.right:
                l = l.right
            l.right = r
            root.left = None
        
    preorder(root)