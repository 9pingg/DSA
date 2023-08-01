// basic level order traversal
// start from root (1st diagonal), add all root.right to res and if there is root.left add to queue

vector<int> diagonal(Node *root)
{
    queue<Node*> q;
    vector<int> res;
    if (root)
        q.push(root);
    else return res;
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* node = q.front();
            q.pop();
            
            while(node){
                res.push_back(node->data);
                if(node->left != NULL){
                    q.push(node->left);
                }
                node = node->right;
            }
        }
    }
    return res;
}