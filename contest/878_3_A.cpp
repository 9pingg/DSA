#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    string s;
    while(t--){
        cin >> n;
        cin >> s;
        char ch = s[0];
        string a = "";
        for (int i = 1; i < n; i++){
            if (s[i] != ch) continue;
            else {
                a += ch;                    
                if (i + 1 < n) {
                    ch = s[i + 1];
                    i++;
                }
            }
        }
        cout << a << endl;
    }   
    return 0;
}