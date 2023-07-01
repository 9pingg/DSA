
// BASICALLY THE SAME VERSION FOF Q-10 instead of max length of subarray which sums to k, we need count of
// subarrays which sum to K.

// optimal : o(n)

int subarraySum(vector<int>& a, int k) {
    unordered_map<int,int> m; // sum, prefix_sum_pos
    int prefix_sum = 0;
    int count = 0;
    for(int i = 0 ; i < a.size() ; i++){
        prefix_sum += a[i];
            // inc count
        if(prefix_sum == k) count++;
        if(m.find(prefix_sum - k)!=m.end()){
            count += m[prefix_sum - k];
        }
        m[prefix_sum]++; // this statement should come after the if statement (find() one)
                        // if the k = 0, and we add prefix sum in map then it would always find this 
                        // prefixsum in map in if block and counter will inc which is not right. 
    }
    return count;
    
}