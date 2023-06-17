
// QUES NOT EASY 
// REDO 

// approach: traverse l to r, top to bottom, r to l and bottom to top
// but isme yeh sari values hongi update

// jaise l always hoga update +1 sae
//OPTIMAL SOLN (one 1 soln it has) O(m*n) space same h 
// MOST IMP statement  == [res.size() < m*n ]
// THIS SHOULDNT BE res.size() == m*n or res.size() <= m*n yeh dono wrong h and size ki statement has to be in every for loop.
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;
    while(res.size() < m*n)
    {
        // store all elements from l to r
        // MOVE RIGHT
        for(int i = left ; i <= right && res.size() < m*n ; i++){  
            res.push_back(matrix[top][i]);
            // top is constant here
        }
        top++;
        // MOVE BOTTOM
        for(int i = top ; i <= bottom && res.size() < m*n; i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        // MOVE LEFT
        for(int i = right; i>= left && res.size() < m*n; i--){
            res.push_back(matrix[bottom][i]);
        }
        bottom--;
        // MOVE TOP
        for(int i = bottom; i>= top && res.size() < m*n; i--){
            res.push_back(matrix[i][left]);                
        }
        left++;
    }
    return res;
}
