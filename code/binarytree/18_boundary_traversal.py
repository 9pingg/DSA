from os import *
from sys import *
from collections import *
from math import *

# Following is the Binary Tree node structure:
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def traverseBoundary(root):
    #  3 steps 
    #  1) left view (no leaf nodes)
    #  2) get all leaf nodes using a traversal (only dfs would work not bfs as leaf nodes can be in diff level)
    #  3) right view (no leaf nodes) (start from bottom of tree to top)
    if root:
        res = [root.data]
    else: return []

    def left_view(root):    
        if root is None: return
        if root.left or root.right: # root should not be root node
            res.append(root.data)

        if root.left: # if left node exits
            left_view(root.left)
        elif root.right: # if no left node then get right node
            left_view(root.right)

    def dfs(root):
        if root is None: return
        dfs(root.left)
        if root.left is None and root.right is None: # append leaf node
            res.append(root.data)
        dfs(root.right)
    
    def right_view(root):
        if root is None: return
        if root.right:
            right_view(root.right)
        elif root.left:
            right_view(root.left)
        if root.left or root.right: # if has a c then append. node here shouldnt be a leaf node
            res.append(root.data)

    left_view(root.left)
    # check if root is a leaf node itself, then no need to dfs
    if not root.left and not root.right: return [root.data]
    dfs(root)
    right_view(root.right)
    return res
