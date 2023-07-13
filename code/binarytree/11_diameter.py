# t: o(n) and s : o(n) when skew tree
class Solution:
    res = 0
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # diameter of tree == maximum number of edges between two nodes
        # diamter = depth (left subtree of root) + depth (root.right) (not true)
        # we have to find l and r for every node because there might be a node whose l and r are greater than root node
        # so not necessary that diameter passes through root node
        def depth(root):
            if root is None: return 0
            l = depth(root.left)
            r = depth(root.right)
            self.res = max(self.res, l+r)
            return 1 + max(l,r)
        depth(root)
        return self.res
    
# what about if nary tree is given still => t: o(n) and s : o(n) when skew tree
# iterate through all child of root node and find the two max depths, both when summed gives the diameter just like binary tree

diameter = 0
def solve(root):
    global diameter

    if (root == None):
        return 0
    # find top 2 
    max1 = 0
    max2 = 0
    for it in range(len(root.child)):
 
        h = solve(root.child[it])
        if (h > max1):
            max2 = max1
            max1 = h
        elif (h > max2):
            max2 = h
    diameter = max(max1 + max2, diameter)
 
    return max1 + 1
