
#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Input : “12abc345def67ghi”
// Output : “12cba345fed67ihg”

bool isdigit(int ch){
    if(ch >= '0' && ch <= '9') return true;
    else return false;
}

bool isalpha(int ch){
    if((ch >= 'a' && ch <= 'z') || (ch>= 'A' && ch <= 'Z')) return true;
    else return false;
}
int32_t main() {
    fastIO();
    string s;
    cin >> s;
    string res = "";
    stack<char> st;

    int n = s.size();
    int i = 0;
    while(i < n){
        while(i < n && isdigit(s[i])) i++;
        // now i at alpha char
        int l = i;
        int h = i;
        // now find the pos of last char in alpha substring
        while(h < n && isalpha(s[i])) {
            i++;
            h++;
        }
        i = h;
        h--;
        while(l < h){
            swap(s[l], s[h]);
            l++;
            h--;
        }
    }
    cout << s;
    return 0;
}