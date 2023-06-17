void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // additional memory approach 
    // O(M+N) space required 
    // itr through the 2d array mark i,j and store in the set_it vector
    // instead of vector we can also use two unoredered sets so i and j do not repeat
    vector<pair<int,int> > set_it;
    for(int i = 0; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(matrix[i][j] == 0){
                set_it.push_back({i,j}); 
            } 
        }
    }
    // after that 
    // O(K(M+N))
    for(int k = 0 ; k < set_it.size(); k++){
        // set all elements 0 with coloumn kj
        for(int i = 0 ; i < m ;i++){
            matrix[i][set_it[k].second] = 0;
        } 
        // set all elements 0 with row ki
        for(int j = 0 ; j < n ;j++){
            matrix[set_it[k].first][j] = 0;
        }        
    }
}

// OPTIMAL APROACH : USES O(1) space so we need to use the matrix itself to notify whether to put 0 in some element or not.

// LEARN : WE USE THE 0th row and 0th colum of the matrix to notify which row or column is to be made entirely 0.


 void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // O(1) space use the same matrix for indicators
    bool col0 = 0; // to notify whether row 0 and col 0 had zeroes in the orignal array
    bool row0 = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(matrix[i][j] == 0){
                if(i == 0) row0 = 1;
                if(j == 0) col0 = 1;

                // mark the row index and col index which needs to be 0
                // if i,j = 0 then rowi and colj is to be made 0. so put m[i][] = 0 which notifies that we need to make row i = 0
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                cout << i << " " << j << endl;
            } 
        }
    }

    // NOTICE : here we start from 1 here not 0.
    // if we start from 0 then we might update our markers made in row0 or col0, so we handle them later
    for(int i = 1 ; i < m ;i++){
        for(int j = 1 ; j < n ; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
                cout << i << " " << j << endl;
            }   
        }
    }
    
    if(row0){
        // set entire coloum0 as 0
        for(int j = 0 ; j < n ; j++){
            matrix[0][j] = 0;
        }
    }
    if(col0){
        // set entire row0 as 0
        for(int i = 0 ; i < m ; i++){
            matrix[i][0] = 0;
        }
    }

    
}
