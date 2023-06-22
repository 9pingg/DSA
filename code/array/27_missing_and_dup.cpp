#include <bits/stdc++.h>
using namespace std;
#define int long long
// https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_6828164?


// missing number easily find out with xor
// genrally we use math to find duplciate number not xor.
// Find the two repeating elements in a given array on gfg uses math for (n+2) size vector
/*
MATH FORMULA REM: 
    (x+y)2 - 4xy = (x+y)2
    if we know sum and pro we can find x-y through which we have two eqns and we can ge x,y
*/

// HERE we need to find both miss and dup, so we use math
// in the question we have n sized vector now it hsould only have elements from 1 to n. (with any one of them being missing or dup)
// ex: for n=4, 1 2 2 4 (3 is miss, 2 is dup)
// brute force O(N^2) => for each i 1 to n we search the count of the i in array.

// better approach : frequency array O(2*N) and O(N) space 


// optimal approach : math
/*
    let x = missing number, y = duplicate number
    S = n * n+1 / 2
    a_sum = sum of array a 
    a_sum - S = y - x 

    CHOICE 2: PRODUCT of numbers OR SUM OF SQAURES
    S^2 = sum of squares of 1 to n =(n*(n+1)*(2*n+1))/6;
    a_sum^2 = same as S^2
    a_sum^2 - S^2 = y2 - x2
    y2-x2 = (y+x) (y-x)
    get y+x and then solve for x and y

*/


// product code this uses sum and product, doesnt work for big inputs as double overflows
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    // Write your code here
        int n = a.size();
        double sum = (n * (n+1)) / 2;
        double pro = 1;
        double a_sum = 0;
        double fact_n = 1;
        for(int i = 0 ; i < a.size(); i++){
            a_sum += a[i];
            pro *= a[i];
            fact_n *= (i+1);
        }
        double diff = sum - a_sum;
        // cout << pro;
        pro = pro/fact_n;
        vector<int> res;
        double pro_1 = 1 - pro;
        double missing = diff/pro_1;
        double duplicate = diff*pro/(pro_1);
        res.push_back(ceil(duplicate));
        res.push_back(ceil(missing));
        cout << duplicate << " " << missing << " " << endl;
        return res;
}

// this will work for large inputs as well uses sum of squares

//NOTE ALWAYS WHEN MULTIPLYING INTEGERSE THEY MAY OVERFLOW SO ALWAYS USE 1LL OR CONVERT THEM TO LONG LONG
vector<int> findMissingRepeatingNumbers1(vector<int> a) {
    // Write your code here
        long long n = a.size();
        long long sum = 1LL *(n * (n+1)) / 2;
        long long sum2 = 1LL * (n * (n+1) * (2*n+1)) / 6;
        long long a_sum = 0;
        long long a_sum2 = 0;
        
        for(int i = 0 ; i < a.size(); i++){
            a_sum += a[i];
            a_sum2 += 1LL * a[i] * a[i];
        }
        long long diff = sum - a_sum; // x-y 
        long long diff2 = sum2 - a_sum2; // x2 - y2
        long long xy = diff2/diff;
        long long x = (xy + diff) / 2;
        long long y = x - diff;
        // y =dup x = missing num
        vector<int> res;
  
        res.push_back(y);
        res.push_back(x);
        
        return res;
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int32_t main() {
    fastIO();
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        vector<int> res;
        int n;
        cin >> n;
        while(n--){
            int val;
            cin >> val;
            res.push_back(val);
        }
        findMissingRepeatingNumbers(res);
    }
    return 0;
}