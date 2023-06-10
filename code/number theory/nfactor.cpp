#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool prime[1000010];
void seive(){
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(int p = 2; p * p < 1000010 ; p++){
        if(prime[p]){
            for(int i = p*p; i < 1000010 ; i+=p){
                prime[i] = 0;
            }
        }
    }
}
int32_t main() {
    fastIO();
    int t;
    cin >> t;
    int a, b, n;
    seive();
    while(t--){
        int count_res = 0;
        cin >> a >> b >> n;
        int state[1000010];
        memset(state, -1, sizeof(state));
        for(int i = a ; i <= b ; i++){
            int count = 0;
            int t = i;
            if(state[t]!=-1) count = state[t];
            else{
                for (int j = 2 ; j <= sqrt(t) ; j++){
                    // i = 6, p_factors = 2, 3
                    if(prime[j] && t % j == 0) {
                        count++;
                        while(t%j == 0){
                           
                            t = t/j;
                        }
                    }   
                }
                if(t > 1) count++;
                // if (prime[i]) count++;
                state[i] = count;
            }
            if (count == n){
                // cout << "i " << i << " count " <<count <<"\n";
                count_res++; 
            }

        }
        cout << count_res << "\n";
    }
    return 0;
}