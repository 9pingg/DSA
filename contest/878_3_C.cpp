#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    int n, k, q, val;
    while(t--){
        cin >> n >> k >> q;
        
        long long count = 0, consecutive_days = 0;
        long long ans;
        for(int i = 0; i < n; i++){
            cin >> val;
           
            if(val <= q) {
                consecutive_days++;
            }
            else {
                int temp = k;
                if (k > consecutive_days || consecutive_days == 0){
                ans = 0;
                }
                else{
                ans =  consecutive_days+1-k;
                k++;
                while (consecutive_days+1 != k){
                    ans += consecutive_days+1-k;
                    k++;    
                }
                }
                k = temp;
                count+=ans;
                consecutive_days = 0;

            }
        }
        if(consecutive_days != 0){
            int temp = k;
            if (k > consecutive_days || consecutive_days == 0){
                ans = 0;
            }
            else{
            ans =  consecutive_days+1-k;
            k++;
            while (consecutive_days+1 != k){
                ans += consecutive_days+1-k;
                k++;    
            }
            
            }
            k = temp;

            count+=ans;
            
        }
        cout << count << endl;
    }
    return 0;
}

