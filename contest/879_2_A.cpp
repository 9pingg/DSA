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
    int t, val, n, temp;
    int count = 0;
    int count_1 = 0;
    int diff;
    cin >> t;
    while(t--){
        cin >> n;
        count = 0;
        count_1 = 0;
        diff = 0;
        temp = n;
        while(temp--){
            cin >> val;
            if(val == -1) count++;
        }
        count_1 = n - count;
        if(count > count_1){ //14 5 5 4, 3-1 1 1 2
            diff = count - count_1;
            count = count - ceil((double)diff / 2);
           
        }
        
        // sum >= 0
        if(count % 2 == 0) cout <<  (ceil((double)diff / 2)) << "\n";
        else cout << (ceil((double)diff / 2) + 1) << "\n";
    }
    return 0;
}