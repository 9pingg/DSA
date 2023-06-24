#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int dp[105][100005];
int solve(int n, int w, vector<int> &wt){
    if(w == 0) return 1;
    else if(n == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    int ans = 0;
    for(int i = 0; i <= wt[n-1] ; i++){
        ans = (ans% MOD + solve(n-1, w-i, wt) % MOD) % MOD;
    }   
    return dp[n][w] = ans %MOD;
}
int32_t main() {
    fastIO();
    int n, target;
    cin >> n >> target;
    vector<int> wt(n);
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        wt[i] = val;
    }
    memset(dp, -1, sizeof(dp));
    // vector<vector<int> > dp(n+1, vector<int>(target+1, -1));
    solve(n, target, wt);
    cout << dp[n][target] << "\n";
   
   
    // for(int i = 0; i <= n; i++){
    //     dp[i][0] = 1; 
    // }
    // for(int i = 0; i <= target; i++){
    //     dp[0][i] = 0;    
    // }
    
    // for(int i = 1; i <= n ; i++){
    //     for(int j = 1 ; j <= target; j++){
    //         if(wt[i-1] <= j){
    //             dp[i][j] = dp[i-1][j-wt[i-1]] + dp[i-1][j];   
    //         }else{
    //             dp[i][j] = dp[i-1][j];   
    //         }
    //     }
    // }
    // cout << dp[n][target];
    return 0;
}