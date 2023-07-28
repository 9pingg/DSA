#include <bits/stdc++.h>
using namespace std;
int solve(int l, int r, int max_val, vector<int> &nums){
    if (l == r || l > r) return 0;
    int a = 0, b = 0, c = 0, d = 0;
    if(l > max_val && nums[l-1] %2 == 0 && nums[l+1] % 2 ==0){
        // max_val = l;
        a = abs((nums[l-1] + nums[l+1]) / 2 - nums[r]) + solve(l+1, r-1, l, nums);
    }
    if(r > max_val && nums[r-1] %2 == 0 && nums[r+1] % 2 ==0){
        // max_val = r;
        b = abs((nums[r-1] + nums[r+1]) / 2 - nums[l]) + solve(l+1, r-1, r, nums);
    }
    if(r > max_val && nums[r-1] %2 == 0 && nums[r+1] % 2 ==0 && nums[l-1] %2 == 0 && nums[l+1] % 2 ==0){
        // max_val = r;
        c = abs((nums[r-1] + nums[r+1]) / 2 - (nums[l-1] + nums[l+1]) / 2) + solve(l+1, r-1, r, nums);
    }
    d = abs(nums[l] - nums[r]) + solve(l+1, r-1, max_val, nums);
    return max(a, max(b, max(c, d)));
}
int main(){
    int n, val;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> val;
        nums[i]= val;
    }
    cout << solve(1, n-2, 0, nums) + abs(nums[n-1] - nums[0]);
}
