// brute force find avg of all subarrays inc count when avg = k

// optimal o(n) using prefix sum and hash
/*
    sum[j] - sum[i] / (j - i) = k
    sum[j] -j*k = sum[i] - i*k
    we store sum[i] - i*k in map
    
    note sum[j] = a0 + a1 + a2 .. + aj
*/

int countKAverageSubarrays(int arr[], int n, int k){    
    unordered_map<int,int> m;
    int prefix_sum = 0;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        prefix_sum += arr[i];
        if(prefix_sum/(i+1) == k) count++;
        if(m.count(prefix_sum - i*k)){
            count++;
        }
        m[prefix_sum - i*k]++;
    }
}

// best way to do this 
// when you subtract k from each element, it becomes a very standard problem (number of subarrays which sum to 0)
/*
let say (a + b + c + d) / 4 = k, where k is the mean, this can be written as (a + b + c + d) = 4k , 
it can be further written as
(a + b + c + d - 4k) = 0
(a - k) + (b - k) + (c - k) + (d - k) = 0
*/
int countKAverageSubarrays(vector<int>& a, int k) {
    unordered_map<int,int> m; // sum, prefix_sum_pos
    int prefix_sum = 0;
    int count = 0;
    for(int i = 0 ; i < a.size() ; i++){
        prefix_sum += a[i]-k;
            // inc count
        if(prefix_sum == 0) count++;
        if(m.find(prefix_sum - 0)!=m.end()){
            count += m[prefix_sum - 0];
        }
        m[prefix_sum]++; // this statement should come after the if statement (find() one)
                        // if the k = 0, and we add prefix sum in map then it would always find this 
                        // prefixsum in map in if block and counter will inc which is not right. 
    }
    return count;
    
}