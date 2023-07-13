"""
A binary tree's maximum depth is the number of NODES(leetcode def)/EDGES(gfg definition) along the longest path from the root node down to 
the farthest leaf node. In number of nodes root and leaf node included.

(NOT SURE) max height and depth is same for a tree but not for a node

"""

# recursive approach o(n), uses auxilary space o(h) 
def maxDepth(self, root: Optional[TreeNode]) -> int:
    if root is None: return 0 # if number of edges then return -1 or number of nodes then return 0
    l = self.maxDepth(root.left) # find depth of left node
    r = self.maxDepth(root.right) # find depth of right node
    return 1 + max(l,r)

# iterative approach o(n), uses space o(n)(when a perfect tree is given) bfs uses queue
