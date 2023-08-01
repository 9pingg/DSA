def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
    # maps key child to parent
    dic = {} 
    # connect child to parent, by doing a simple traversal
    start_node = None
    def dfs(root):
        nonlocal start_node
        if root is None: return
        if root.val == start: 
            start_node = root
        if root.left:
            dic[root.left] = root
        if root.right:
            dic[root.right] = root
        dfs(root.left)
        dfs(root.right)
    dfs(root)

    # mark visited nodes
    visited = {}

    def find(node):
        if node is None or node in visited: return 0
        visited[node] = True
        l = 1 + find(node.left)
        r = 1 + find(node.right)
        p = 0
        if node in dic:
            p = 1 + find(dic[node])
        return max(l, r, p)
    # reduce the count by 1, as it counts the starting node as 1
    return find(start_node)-1