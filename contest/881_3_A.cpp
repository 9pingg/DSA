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
    int t;
    cin >> t;
    while(t--){
        int n;
        
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n ; i++){
            int val;
            cin >> val;
            v[i] = val;
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = n-1;
        int mid = n/2;
        int l1;
        int r1;
        int c = 0;
        while(mid > 2){
            
            r1 = v[r--];
            l1 = v[l++];
            c+= r1-l1;
            mid--;
        }
        cout << c << "\n";
    }
    return 0;
}