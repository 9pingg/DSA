https://leetcode.com/problems/pascals-triangle/description/

// 3 variety of questions 

// 1 find a particular elemetn in row r and col c of pascal triangle answer r-1 C c-1
// so we need to calc factorial which is O(n) better way to calc ncr is 

int nCr_best(int n, int r){
    int n_r = n -r; // 5c3 = 5!/3!*2! = 5*4/ 2*1 (so choose the bigger of r or n-r can cancel it with n!)
    if(n_r > r){
        swap(n_r, r);
    }
    n_r = n-r; // n_r = 2
    int num = 1;
    int d1 = 1; // r (stays 1 because it gets cancelled with n!)
    int d2 = 1; // n-r
    for(int i = 0 ; i < n_r ; i++){ 
        num *= (n-i); // 1 * num, 1 * num * (num-1) 
        d2 *= (n_r - i); // 1 * n_r , 1 * n_r * (n_r-1)
    }
    // cout << num << " " << d2 << endl;
    return num / (d1 * d2);
}


// 2 find the entire row r of pascal triangle

/* 
Pseudocode: 
    row r has r elements
    // o(n * r)
    for i = 1 to r:
        vector.add(r-1 C i-1)
*/

// 3 print entire pascal triangle

vector<vector<int>> generate(int n) {
    vector<vector<int> > res (n);
    res[0] = {1};
    if(n == 1) return res;
    for(int i = 1 ; i < n ; i++){
        res[i].push_back(1);
        for(int j = 0; j < i-1; j++){ 
            res[i].push_back(res[i-1][j] + res[i-1][j+1]);
        }
        res[i].push_back(1);
    }
    return res;
}