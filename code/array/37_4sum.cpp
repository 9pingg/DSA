https://leetcode.com/problems/4sum-ii/description/

// same problem as two sum but just 4 arrays given
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int res = 0;
    // sum[i,j] = count
    // o(n^2)
    unordered_map<int , int> m;
    int n = nums1.size();
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            m[nums1[i] + nums2[j]]++;
        }
    }

    for(int k = 0 ; k < n; k++){
        for(int l = 0 ; l < n ; l++){
            if(m.count(-nums3[k] - nums4[l])){
                res += m[-nums3[k] - nums4[l]];
            }
        }
    }
    return res;
}