// 
vector<int> topView(Node *root)
{   
    // node with its col
    queue<pair<Node*, int>> q;
    
    if(root != NULL) q.push({root, 0});
    map<int, int> m; 
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size ;i++){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* node = p.first;
            int col = p.second;
            // col doesnt exist add this value, if it does then dont add
            // basically add the first node data which comes with col.
            
            // the first node in every line is top view
            if(!m.count(col)) m[col] = node->data;
            
            if(node->left != NULL){
                q.push({node->left, col-1});
            }
            if(node->right != NULL){
                q.push({node->right, col+1});
            }
        }
    }
    vector<int> res;
    for(auto it : m){
        res.push_back(it.second);
    }
    return res;
}