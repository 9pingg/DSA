# same as before, but p_index starts from n-1 and right subtree is called, can be easily explained using the 
# examples given on leetcode site.
def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
    # build the map
    inorder_map = {}
    
    i = 0
    for num in inorder:
        inorder_map[num] = i
        i = i +1
    #in postorder the root node is always at n-1, start p_index from n-1
    p_index = len(postorder) - 1

    def helper(left, right):
        nonlocal p_index
        if left > right : return None

        # make root
        root = TreeNode(postorder[p_index])

        # now find the pos, of the root in inorder
        i_index = inorder_map[postorder[p_index]]
        p_index = p_index -1

        # all the values right of i_index belong to the right subtree 
        root.right = helper(i_index+1, right)
        # all the values left of i_index belong to the left subtree
        root.left = helper(left, i_index -1)
        return root

    return helper(0, len(inorder)-1)