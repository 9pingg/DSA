"""
constructing a unique bt from traversals given?

   pre and post order given no unique bt can be constructed
   inorder is needed for it to be unique.
   so pre and inorder, post and inorder can be used to construct unique bts.

    The intuition behind the algorithm is to start by identifying the root of the binary tree from the first 
    element of the preorder traversal. Then, we can use the root to divide the inorder traversal into left and 
    right subtrees. We can then recursively apply the same process to the left and right subtrees to construct
    the entire binary tree.

    To do this efficiently, we can use a hash map to store the indices of elements in the inorder traversal. 
    This allows us to quickly find the position of the root in the inorder traversal and divide the traversal 
    into left and right subtrees.

    t : o(n)
    s : o(n) + o(n) (map + rec stack)
"""
def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    # maps inorder values to their index in arr
    inorder_map = {}
    for i, num in enumerate(inorder):
        inorder_map[num] = i
    print(inorder_map)
    # left and right are for inorder
    # p_index is for postorder
    p_index = 0
    def helper(left, right):
        nonlocal p_index
        if left > right: return None
        root = TreeNode(preorder[p_index])
        # find the root's position in inorder
        i_index = inorder_map[preorder[p_index]]
        p_index = p_index + 1 # preorder[p_index] taken so increment it
        # the left subtree consists of all the values from left to i_index-1
        root.left = helper(left, i_index-1)
        # the right subtree consists of all the values from i_index+1 to right
        root.right = helper(i_index+1, right)
        return root
    
    return helper(0, len(inorder)-1)