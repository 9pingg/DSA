#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void print_v(vector<int> &v){
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}

void bubblesort(vector<int> &arr, int n){
    bool noswap = 0;
    while(!noswap){
        noswap = 1;
        for(int i = 0; i < n-1; ++i){  
            if(arr[i]> arr[i+1]){
                swap(arr[i], arr[i+1]);
                noswap = 0;
            }
        }
    }
    print_v(arr);
}

int32_t main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--){
        vector<int> v = {5,2,4,5,7,3,2,1,9};
        bubblesort(v, v.size());
    }
    return 0;
}