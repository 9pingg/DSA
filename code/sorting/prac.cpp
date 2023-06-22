#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int fact(int n){
    if (n <= 1) return 1;
    return n * fact(n-1);
}
int nCr(int n, int r){
    return fact(n) / (fact(r) * fact(n-r));
}

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
// iterative approach O(n) + O(n-r) + O(r) = O(2n)
int nCr_itr(int n, int r){
    int n_r_fact = 1;
    int n_r = n-r;
    int n_fact = 1;
    int r_fact = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i <= r){
            r_fact = r_fact * i;
        }          
        if(i <= n_r){
            n_r_fact = n_r_fact * i;
        }
        n_fact = n_fact * i;
    }
    return n_fact / (r_fact * n_r_fact);
}
int32_t main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--){
        cout << nCr(15,5) << endl;
        cout << nCr_best(15,5) << endl;
        cout << nCr_itr(15, 5) << endl;

    }
    return 0;
}