// clockwise rotation of given matrix do it in O(1)

// Brute force copy the matrix into another and makes updates.
// so element i,j points to m-j,i in new matrix
// O(n2), O(n2) REDUCE SPACE COMPLEXITY
void rotate(vector<vector<int>>& matrix) {
        auto mm(matrix);
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                matrix[i][j] = mm[m-1-j][i];
            }
        }
        return ; 
}

// Optimal O(1) space

// its basically a geometry question 
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry  (i,j => j,i)
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/// (basically reverse and then transpose)
void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i ++){
            for(int j = i ; j < n ; j++){
              swap(matrix[i][j], matrix[j][i]);
            }
        }
        return ; 
}


/*
 * anticlockwise 
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/

void rotate(vector<vector<int>>& matrix) {
        for(vector<int> &v : matrix){
            reverse(v.begin(), v.end());
        }
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i ++){
            for(int j = i ; j < n ; j++){
              swap(matrix[i][j], matrix[j][i]);
            }
        }
        return ; 
}