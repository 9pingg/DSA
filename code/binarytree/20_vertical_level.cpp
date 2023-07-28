https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
struct Queue_Node{
    TreeNode* node;
    int x;
    int y;
};
// Time Complexity: O(N*logN*logN*logN)  map x map y and then add node->val in multiset for n nodes = logN*logN*logN * N nodes
// Space Complexity: O(N) storing n nodes


// diff part of the question is to sort values when row and col is same, this requries multiset

vector<vector<int>> verticalTraversal(TreeNode* root) {
    // queue node has 3 values => node, x, y (level)
    queue<Queue_Node> q; 
    if(root != NULL) q.push({root, 0, 0});
    struct Queue_Node queue_node; 
    // maps[x][y] = {values}
    map<int, map <int, multiset<int>>> m;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size ; i++){
            // y (level) would be same for all the nodes popped in this loop
            queue_node = q.front();
            q.pop();
            TreeNode* node = queue_node.node;
            int x = queue_node.x;
            int y = queue_node.y;
    
            m[x][y].insert(node->val);

            if(node->left != NULL){
                q.push({node->left, x-1, y+1 });
            }
            if(node->right != NULL){
                q.push({node->right, x+1, y+1 });
            }
        }          
    }
    // now storing the collected values in m[x][y] to res.
    vector<vector<int>> res;
    vector<int> col = {};
    for(auto it : m){   
        auto x = it.second;
        col = {};
        for(auto itt: x){
            auto y = itt.second;
            for(int val : y){
                col.push_back(val);
            }
        }
        res.push_back(col);
    }
    return res; 
}

// gfg has the same question but with no sorting of nodes at same x and y
// as no sorting is required the y (level) variable is not reqd.
// o(n * log(n))
vector<int> verticalOrder(Node *root)
{
    queue<Queue_Node> q; 
    if(root != NULL) q.push({root, 0, 0});
    struct Queue_Node queue_node; 
    
    // unordered_,map doesnt work because we want the 
    // vector which has elements with min(x) val at the very first so use map
    // unordered_map<int, vector<int>> m; 
    
    map<int, vector<int>> m;
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size ; i++){
            // y (level) would be same for all the nodes popped in this loop
            queue_node = q.front();
            q.pop();
            Node* node = queue_node.node;
            int x = queue_node.x;
            int y = queue_node.y;
            
            m[x].push_back(node->data);

            if(node->left != NULL){
                q.push({node->left, x-1, y+1 });
            }
            if(node->right != NULL){
                q.push({node->right, x+1, y+1 });
            }
        }          
    }
    vector<int> res;
    // o(n) to convert form a map to vector as n elements
    
    for(auto it : m){
        for(int val : it.second){
            res.push_back(val);    
        }
    }
    return res;
    
}

// can do it without the struct also 

vector<int> verticalOrder(Node *root)
{   
    // node with its col
    queue<pair<Node*, int>> q;
    
    if(root != NULL) q.push({root, 0});
    map<int, vector<int>> m; 
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size ;i++){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* node = p.first;
            int col = p.second;
            // col doesnt exist add this value, if it does then dont add
            // basically add the first node data which comes with col.
            m[col].push_back(node->data);
            
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
        for(auto val : it.second){
            res.push_back(val);    
        }
        
    }
    return res;
}