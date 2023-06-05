#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> m;
    int n;
    cin >> n;
    int val;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    while(n--){
        cin >> val;
        m[val]++;
    }
    int count = 0;
    count += (m[4]+ m[3]);
    m[1] = m[1] - m[3];
    if (m[2] % 2 == 0) count += (m[2] / 2);
    else{
        count += floor(m[2]/2) + 1;
        m[1] = m[1] - 2;
    }
    if (m[1] > 0 && m[1] % 4 == 0) count += m[1] / 4;
    else if (m[1] > 0 && m[1] % 4 != 0) count += floor(m[1] / 4) + 1;
    cout << count;
    return 0;
}