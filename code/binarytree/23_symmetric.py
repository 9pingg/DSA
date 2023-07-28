# non optimal aproach o(n) traverse every node in left and then traverse every node in right 
# basically dfs (any here inorder) left subtree and right subtree. but there is a twist for right subtree traverse right nodes first.
def isSymmetric(self, root) -> bool:
        r1 = []
        r2 = []
        def dfs(root):
            if root is None: 
                r1.append(root)
                return
            r1.append(root.val)
            dfs(root.left)    
            dfs(root.right) 
        def dfs1(root):
            if root is None: 
                r2.append(root)
                return
            r2.append(root.val)
            dfs1(root.right) 
            dfs1(root.left)    
        dfs(root.left)
        dfs1(root.right)
        
        if r1 == r2: return True
        else: return False

# combining this in one function
# optimal as we traverse 2 nodes so o(n /2) as we traverse 2 nodes at once

def isSymmetric(self, root) -> bool:

    def dfs(root1 ,root2):
        if not root1 and not root2: return True
        if not root1: 
            return False
        if not root2:
            return False
        
        if root1.val != root2.val: return False
        
        return dfs(root1.left, root2.right) and dfs(root1.right, root2.left) 

    return dfs(root.left, root.right)
