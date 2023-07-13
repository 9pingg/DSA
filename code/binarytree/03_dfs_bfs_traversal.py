# recursive way to traverse  
# all traversals are o(n) and s: o(h)
#T: o(n) where n = number of nodes
# S: O(n) when tree is like a linked list or generally o(h) where h is height of the tree
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


# level order = bfs
# two ways : 1) recursive and 2) iterative using queue
def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

    res = []
    def bst(root, level): 
        if root is None: return
        if len(res) == level: # NOTE: this condition, not easy to get on first try depth would only be eq to size of res when no element from that level is added to the list
            res.append([root.val])
        else:
            res[level].append(root.val)
        bst(root.left, level+1)
        bst(root.right, level+1)
    bst(root,0)
    return res
# itr code uses deque or queue
def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    q = collections.deque()
    if root is None: return None
    res = []
    q.append(root)
    while len(q)!=0:
        cur_size = len(q)
        t = []
        while cur_size:
            cur = q.popleft()
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
            t.append(cur.val)
            cur_size -= 1
        res.append(t)
    return res
""" cpp code for the same
vector<vector<int>> levelOrder(TreeNode* root) {    
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == NULL) return res;
    vector<int> t;
    q.push(root);
    while (!q.empty()){
        int cur_size = q.size();
        // t to store all nodes of level k
        // pop one node and add left and right node of that node
        t = {};
        while(cur_size--){
            TreeNode* cur = q.front();
            q.pop();
            t.push_back(cur->val);
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
        res.push_back(t);
    } 
    return res;
}
"""
