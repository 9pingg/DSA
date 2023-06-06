#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int main() {
    int t;
    cin >> t;
    unordered_map<string, int> m;
    string s;
    while(t--){
       cin >> s;
       if (m.count(s) > 0){
            string temp = to_string(m[s]);
            m[s] = m[s]+1;
            s += temp;
           
            cout << s << endl;
       }
       else{
        m[s]++; 
        cout << "OK" << endl;
       }
       
    }
    return 0;
}
