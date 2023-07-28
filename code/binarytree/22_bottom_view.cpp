vector<int> bottomView(Node *root)
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
            // bottom view consists of the last node that appears at this col
            // the last node in every line is bottomview.
            m[col] = node->data;
            
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