#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int seq_xor(vector<vector<int> > &dp, vector<int> &v, int val, int n, int check, int pos)
{
    if()
    // initialization
    int n = dp[0].size();
	for(int i = 0 ; i<= m ; i++){dp[i][0] = 1;}
    for(int i = 0 ; i <= n ; i++){dp[0][i] = 0;}
	dp[0][0] = 0;a1

    // choice 
	for (int i=1; i<=m; i++){
        for (int j = 0; j<=n; j++){
            dp[i][j] = dp[i-1][j|v[i-1]] + dp[i-1][j];
        }
    }
	return dp[m][check];
}
int32_t main() {
    fastIO();
    int t, val, a, x, check;
    cin >> t;
    vector<int> v;
    int q = (int)(log2(1025) + 1);
    int mx = (1 << q) - 1;
   
    
    while(t--){
        cin >> a >> x;
        
        if(a == 1){
            v.push_back(x);
        }else if(a == 2){
            vector<vector<int> >dp(1025, vector<int> (mx, -1));
            if(v.size() != 0) cout << seq_xor(dp, v,x) << "\n";
            else cout << "ans0" << endl;
        }
    }
    return 0;
}