"""
Complexity of finding node is O(h), Cases 1,2,3 is O(1). Complexity of Case 4 is O(h) as well,
because we first find succesor and then apply one of the Cases 1,3 only once. So, overall complexity is O(h). 
Space complexity is O(h) as well, because we use recursion and potentially we can find our node in the bottom of tree.
"""


def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
    # whenerver update is to be made in tree 
    # always make updates root.left = temp, not like this root = temp 
    if root is None: return root
    # helper function
    def delNode(root, val):
        if root is None: return None
        
        if root.val == val:
            # 1 no c 
            left = root.left
            right = root.right
            if left is None and right is None:
                # root = None
                return None 
            # 2 only 1 c
            elif left and right is None:            
                # root now eq to root.left
                return root.left
            elif right and left is None:
                # root now eq to root.right
                # root = root.right
                return root.right
            # 3 both c
            else:
                # find min in right subtree or max in left subtree

                # move to right subtree
                cur = root
                cur = cur.right
                # to find min just iterate to the left most node / for
                # max w itr to right most node
                while cur.left:
                    cur = cur.left
                
                # after getting to that node change the root nodes value to this
                # and delete the cur node which is in the right subtree
                root.val = cur.val
                root.right = delNode(root.right, root.val)  
                return root
        # seaching for the node to be deleted
        elif root.val > val:
            if root.left:
                root.left = delNode(root.left, val)
                return root
            else:
                return root
        elif root.val < val:
            if root.right:
                root.right = delNode(root.right, val)
                return root
            else:
                return root
    root = delNode(root, key)
    return root