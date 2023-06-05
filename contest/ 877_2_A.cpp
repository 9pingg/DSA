#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flg = 0;
        long long h = INT_MAX;
        long long l = INT_MIN;
        long long x;
       
        while(n--){
            cin >> x;
            if (x < 0){
                h = min(x, h);
                flg = 1;
            }else{
                l = max(x, l);
                
            }

        }

        if (flg) cout << h << endl;
        else cout << l << endl;
    }
}