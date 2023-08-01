#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


void static_check(){
    static int a = 0; // this is diff than the static var defined in main
    a++;
    cout << a << " ";
}
int32_t main() {
    fastIO();
    static int a = 5;
    static_check();
    static_check();
    cout << static_check :: a;
    return 0;
}