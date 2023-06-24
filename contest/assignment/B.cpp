#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N_start = 0;
int K_start = 0;
int solve(int n, int k, vector<pair<int,int> > &cost, vector<vector<int> > &dp) {
    if(n == 0){
        if(N_start - k >= K_start) return 0;
        else return INF;
    }
    if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = min(cost[n-1].second + solve(n-1, k-1, cost,dp), cost[n-1].first + solve(n-1, k, cost,dp));
}
int32_t main() {
    fastIO();
    int t;
    cin >> t;
    int N, K, val1, val2;
    vector<vector<int> > dp(1001, vector<int> (1001, -1));
    while(t--){
        cin >> N >> K;
        N_start = N;
        K_start = K;
        vector<pair<int,int> > cost(N);
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N ; j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0 ; i < N ; i++){
            cin >> val1 >> val2;
            cost[i].first = val1;
            cost[i].second = val2;
        }
        // memset(dp,-1,sizeof(dp));
        cout << solve(N, N, cost, dp) << "\n";
    }
    return 0;
}