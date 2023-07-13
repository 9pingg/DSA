"""
2 ways to do this:
1) easy way not optimal: do a bfs but in odd levels we need to reverse the list. uses queue o(n) + o(n) s: o(n)
2) optimal uses dequeue no reverse of list required o(n) s: o(n)
"""
# using only : append() and popleft() and reverse
def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if root is None : return 
    q = collections.deque()
    q.append(root)
    res = []
    while len(q) > 0: 
        size = len(q)
        level = []
        while size:
            cur = q.popleft()
            level.append(cur.val)
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
            size -= 1
        if not self.flg: level.reverse()
        res.append(level)
        self.flg = self.flg ^ 1
        print(self.flg)
        
    return res

# using append(), appendleft(), pop(), popleft()
# remember they are always used in pairs if we popleft then append is used
# if we use pop then appendleft is used

zigzag = 0 # dir l to r
def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if root is None : return 
    q = collections.deque()
    q.append(root)
    res = []
    while len(q) > 0: 
        size = len(q)
        level = []
        while size:
            if not self.zigzag: # behave like a queue
                cur = q.popleft()
                level.append(cur.val)
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
            
            else: # behave like a stack
                cur = q.pop()
                level.append(cur.val)
                if cur.right:
                    q.appendleft(cur.right)
                if cur.left:
                    q.appendleft(cur.left)
            size -= 1
        
        res.append(level)
        self.zigzag = self.zigzag ^ 1    
    return res
