// https://leetcode.com/problems/binary-tree-right-side-view/description/

// all nodes are visisted so o(n) and s: o(n)
// the last node of each level becomes the right view

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def solve(root, level):
            if root is None: return
            if len(res) == level: res.append(root.val) // notice the right most node of the tree is added in the list
            if root.right: solve(root.right, level+1) // right before left make it so, the first node is the rightmost node
            if root.left: solve(root.left, level+1)
            
        solve(root, 0)
        return res


vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    if(root != NULL){
        q.push(root);
    } 
    while(!q.empty()){
        int cur_size = q.size();

        for(int i = 0; i < cur_size ; i++){
            TreeNode* node = q.front();
            q.pop();
            if(i == cur_size-1) res.push_back(node->val);
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return res;

}