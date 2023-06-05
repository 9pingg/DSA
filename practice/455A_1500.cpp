#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,val;
    long long dp[100005]={0};
    long long count[100005]={0};
    cin >> t;
    for( int i = 0 ; i < t ; i++ ){      
         cin>>val;     
         count[val]++;
    }
    dp[0] = 0;
    dp[1] = count[1];
    
    for(int i=2;i<= 100000;i++){
        dp[i]=max(dp[i-1], dp[i-2] + i*count[i]);
    }
    cout<<dp[100000];
    return 0;

}