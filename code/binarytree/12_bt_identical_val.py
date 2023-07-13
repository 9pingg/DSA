def isIdentical(self,root1, root2):
    # if both nodes are null then return true
    if root1 is None and root2 is None: return True
    # one of them reaches None value
    if root1 is None or root2 is None: return False
    # value different
    if root1.data != root2.data: return False
    
    l = self.isIdentical(root1.left, root2.left)
    r = self.isIdentical(root1.right, root2.right)
    return l & r