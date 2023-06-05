#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, t, p1, p2;
    cin >> n;
    cin >> t;
    const int K = 1000000007;
    long long dp[500007], prefix[500007];

    for (int i = 0; i < t; i++) {
        prefix[i] = i+1;
        dp[i] = 1;
        
    }
    for (int i = t; i <= 500000; i++) {
        dp[i] = ((dp[i-1] % K) + (dp[i-t] % K)) % K;
        prefix[i] = ((prefix[i-1] % K) + (dp[i] % K)) % K;
    }
    for (int i = 0; i < n; i++) {
        cin >> p1 >> p2;
        long long ans = (prefix[p2] % K) - (prefix[p1-1] % K);
        if (ans < 0 ) ans+=K;
        else ans+=0;
        cout << ans<<endl;
    }
}