#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> &v){
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}



//brute force make two separate vectors pos and neg to store nums
// then add in orignal array nums[2*i] = pos[i]; here O(2*N) as 2 traversals

// optimal soln : one pass
// easy question O(N), O(n)
// checked but in submissions O(n) space is the only available answer

// if num > 0 add 2i position else add num at 2i+1 position
vector<int> rearrangeArray(vector<int>& nums) {
        int p = 0;
        int n = 1;
        int N = nums.size();
        vector<int> res(N);
        for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] > 0) {
                    res[p] = nums[i];
                    p+=2;
                }       
                else{
                    res[n] = nums[i];
                    n+=2;
                }
        }
    return res;
}

int32_t main() {
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        vector<int> nums = {-1,1};
        vector<int> a = rearrangeArray(nums);
        print_v(a);
    }
    return 0;
}