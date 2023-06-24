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
    int t, x, y;
    // cin >> t;
    t = 1;
    while(t--){
        cin >> x >> y;
        if(x == y) cout << 0;
        else if((x >= 0 && y >= 0)){
            if(x > y){
                int ans = x - y +2;
                int an =  x+1;
                if(y != 0) cout << ans;
                else cout << an;
            }else{
                int ans = y-x;    
                cout << ans;
            }
        }
        else if((x <= 0 && y <= 0)){
            if(x > y){
                int ans = 2 + (-y) + x;
                int an = (-y) + 1;
                if (x != 0)cout << ans;
                else cout << an;
            }else{
                int ans = y-x;    
                cout << ans;
            }
        }
        else if(x < y){
                if(-x > y){
                    int ans = (-x - y)+ 1;
                    cout << ans;
                }else{
                    // int ans = (llabs(y+x) + 1);
                    int ans = (y - (-x)) + 1;
                    cout << ans;
                } 
        }               
        else if(x > y){
            if(-y  > x){
                int ans = (-y - x) + 1;
                cout << ans;
            }else{
                int ans = x+y +1;
                cout << ans;
            }
        }
    }
    return 0;
}