/*
width of a level: the length btw the end nodes of a level (inclusive).
width is always level based, calc for each level.

max width: find width of all level choose maximum.
*/

// level order traversal, suppose a perfect tree is given lets number it level order wise
// starting with root at 0. p = i then left child = 2i+1 and right child = 2i+2. so we need to maintain there position in tree.
// for each level find the left most node and the right most node.
// if only one node in a level then its width is 1

int widthOfBinaryTree(TreeNode* root) {
    // max width is of a level, find teh maximum width present in all of the levels
    // level order traversal
    queue<pair<TreeNode*, int>> q;
    if(root != NULL){
        q.push({root, 0}); // 0 based indexing
    } 
    
    int res = 0;
    while(!q.empty()){
        int cur_size = q.size();
        int min_pos = INT_MAX; // left most node pos
        int max_pos = INT_MIN; // right most node pos
        for(int i = 0; i < cur_size ; i++){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int pos = it.second;
            min_pos = min(min_pos, pos);
            max_pos = max(max_pos, pos);
            
            if(node->left != NULL) q.push({node->left, 1LL*2*pos+1}); 
            if(node->right != NULL) q.push({node->right, 1LL*2*pos+2});
            // why multiplied by 1LL, notice how pos gets mutiplied by 2 every level
            // so at level 31 pos = 2^31 (might overflow)
            // in the question the tree can have level > 64 this means even if pos is long long type it would still overflow.
            // so we just take the right 31 bits when storing in pos

            // or simply make pos unsigned long long

        }
        // if a level has only one node, then max and min pos would be same
        // then max_pos-min_pos == 0
        res = max(res, max_pos - min_pos + 1);
    }

    return res;
}
