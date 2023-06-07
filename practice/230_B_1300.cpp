#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000010

bool prime[SIZE];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void seive(long long n){
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(long long p = 2; p * p <= n ; p++){
        if (prime[p]){
            for(long long i = p * p ; i <= n ; i += p){
                prime[i] = 0;
            }
        }
    }
}
int main() {
    fastIO();
    int t;
    cin >> t;
    long long val;
    seive(1000001);
    while(t--){
        cin >> val;
        long long x = sqrt (val);
        if (x * x == val && prime[x]){
            cout << "YES" << "\n";
        }else {
        cout << "NO" << "\n";
        }
    }
}

