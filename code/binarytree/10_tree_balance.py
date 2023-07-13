
# two ways to do this iterative and recursive. iterative make a queue do a bst in the inner while loop update level and check
class Solution:
    res = True
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # tree is balanced when for every node depth of l subtree, depth of r subtree
        # follows this abs(l-r) <= 1
       
        def solve(root):
            if root is None: return 0
            l = solve(root.left)
            r = solve(root.right)
            print(l,r)
            if abs(l-r) > 1: self.res = False
            return 1 + max(l,r)
        solve(root)
        return self.res
    
# better way so that rec calls are less optimal appraoch
def isBalanced(self, root: Optional[TreeNode]) -> bool:
    # tree is balanced when for every node depth of l subtree, depth of r subtree
    # follows this abs(l-r) <= 1
    
    def solve(root):
        if root is None: return 0
        l = solve(root.left)
        if l == -1: return -1
        r = solve(root.right)
        if r == -1: return -1
        if abs(l-r) > 1: return -1
        return 1 + max(l,r)
    if solve(root) == -1 : return False
    else: return True