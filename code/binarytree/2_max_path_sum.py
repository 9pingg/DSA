def maxPathSum(self, root: Optional[TreeNode]) -> int:
    res = float('-inf')
    def dfs(root):
        nonlocal res
        if root is None: return 0
        l = dfs(root.left)
        r = dfs(root.right)
        if(l < 0): l = 0 # dont want sum of left subtree if it is < 0
        if(r < 0): r = 0 # dont want sum of right subtree if it is < 0
        # current path sum, root is choosen to be curving point
        res = max(res, r + l + root.val)
        # we want to keep one straight path
        return  root.val + max(l, r)
    dfs(root)
    return res