#include <bits/stdc++.h>
using namespace std;
int solution(){
    int t;
    cin >> t;
    int count_e = 0;
    int count_o = 0;
    int val;
    vector<int> v(3);
    for (int i = 0; i <= 2 ; i++){
        cin >> val;
        v[i] = val;
        if (val % 2 == 0) count_e++;
        else count_o++;
    }
    if (count_o && count_e) {
        if(count_o < count_e){
            for (int i = 0; i <= 2 ; i++){
                val = v[i];
                if (val % 2 != 0) return i+1;
            }
        }
        else {
            for (int i = 0; i <= 2 ; i++){
                val = v[i];
                if (val % 2 == 0) return i+1;
            }
        }
    }

    if(count_o < count_e)
            for (int i = 3; i < t ; i++){
                cin >> val;
                if (val % 2 != 0) return i+1;
            }
    else {
        for (int i = 3; i < t ; i++){
            cin >> val;
            if (val % 2 == 0) return i+1;
        }
    }
    return -1;
}
int main() {
    cout << solution();
    return 0;
}