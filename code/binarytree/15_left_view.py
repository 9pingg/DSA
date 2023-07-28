# recursive way to solve it. basically add the first element in a level, if added dont add anymore nodes from that level.
# o(N) ,s: o(h) or o(n) only
res = []
def solve(root, level):
    if root is None: return
    if(len(res) == level): res.append(root.data)
    solve(root.left, level+1)
    solve(root.right, level+1)
    
def LeftView(root):
    solve(root, 0)
    return res

# other way is level order traversal, using queue only add the first element of the level
'''
vector<int> leftView(Node *root)
{
    vector<int> res;
    queue<Node*> q;
    if (root != NULL) q.push(root);

    
    while(!q.empty()){
        int size = q.size();
        int flg = 1;
        while(size--){
            Node* node = q.front();
            q.pop();
            if(flg){
                res.push_back(node->data);
                flg = 0;
            }
            if (node->left != NULL){
                q.push(node->left);
            }
            if (node->right != NULL){
                q.push(node->right);
            }
        }
    }
    return res;
}
'''
