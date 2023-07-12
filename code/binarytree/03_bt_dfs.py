# recursive way to traverse
def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    res = []
    def inorder(root):
        if root is None: return
        inorder(root.left)
        res.append(root.val)
        inorder(root.right)
    inorder(root)
    return res 

def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    res = []
    def pre_order(root):
        if root is None: return None
        res.append(root.val)
        pre_order(root.left)
        pre_order(root.right)
    pre_order(root)
    return res

def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    res = []
    def post_order(root):
        if root is None: return
        post_order(root.left)
        post_order(root.right)
        res.append(root.val)
    post_order(root)
    return res

