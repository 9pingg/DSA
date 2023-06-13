#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int32_t main() {
    fastIO();
    int t,val;
    cin >> t;
    while(t--){
        cin >> val;
        if(val <= 4) cout << "Bob" <<"\n";
        else cout << "Alice" << "\n";
    }
    return 0;
}
