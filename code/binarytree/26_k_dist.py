def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
    # maps key child to parent
    dic = {} 
    # connect child to parent, by doing a simple traversal
    def dfs(root):
        if root is None: return
        if root.left:
            dic[root.left] = root
        if root.right:
            dic[root.right] = root
        dfs(root.left)
        dfs(root.right)

    dfs(root)

    res = []
    # mark visited nodes
    visited = {}
    
    # find all nodes at a dist k from target 
    def find(node, k):
        if node is None or node in visited: return
        visited[node] = True
        if k == 0: 
            res.append(node.val)
        find(node.left, k-1)
        find(node.right, k-1)
        if node in dic: 
            find(dic[node], k-1)
    find(target, k)
    return res