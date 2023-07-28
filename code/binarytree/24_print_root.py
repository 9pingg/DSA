# all nodes visited o(n)

def binaryTreePaths(self, root):
    res = []
    def isleaf(root):
        if root.left is None and root.right is None: return True
        else: return False
    
    def solve(root, path):
        if isleaf(root):
            # add leaf node and the path is complete
            path += str(root.val)
            res.append(path)
            return
        # add current node to path
        path += str(root.val) + "->"
        if root.left:
            solve(root.left, path)
        if root.right:
            solve(root.right, path)
    
    solve(root, "")
    return res