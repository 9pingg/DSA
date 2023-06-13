#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

long long gcd_r(long long a, long long b){
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd_r(b, a%b);
}

struct result{
    long long x;
    long long y;
    long long gcd;
    int a;
};
result extended_euclidean(long long a, long long b){
    if (b == 0){
        result res;
        res.x = 1;
        res.y = 0;
        res.gcd = a;
        return res;
    }
    // x = y1
    // y = x1 - int(a/b) * b (theory)
    result res_1 = extended_euclidean(b, a%b);
    result res;
    res.x = res_1.y;
    res.y = res_1.x - floor(a/b) * res_1.y;
    res.gcd = res_1.gcd;
    return res;
}
result diophantine_eqn_any_soln(long long a, long long b, long long c){
    long long gcd = gcd_r(a, b);
    if (c % gcd == 0) {
        long long k = c / gcd;
        result r = extended_euclidean(a, b);
        r.x = r.x * k;
        r.y = r.y * k;
        r.a = 1;
        return r;
    }
    return {1,1,1,0};
}


int main() {
    fastIO();
    long long a, b, c;
    cin >> a >> b >> c;
    result r = diophantine_eqn_any_soln(a, b, -c);
    if (r.a){
        cout << r.x << " " << r.y;
    }
    else cout << -1;
    
    return 0;
}