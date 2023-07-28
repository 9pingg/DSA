# can also be done using level order traversal
def isParentSum(root):  
    def isleaf(root):
        if root.left is None and root.right is None: return True
        else: return False

    def solve(root):
        if root is None: return True
        if isleaf(root): return True

        if root.left:
            root.data -= root.left.data
        if root.right:
            root.data -= root.right.data

        if root.data != 0:
           return False
        return solve(root.left) and solve(root.right)

    return solve(root)
    
