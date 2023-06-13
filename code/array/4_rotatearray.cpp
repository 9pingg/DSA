class Solution {
public:
// basic approach convert vector to dequeue // O(2*N + K) simple pop from back and push at front
    void rotate(vector<int>& a, int k) {
        int val = 0;
        k = k %a.size();
        deque<int> v(a.begin(), a.end());
        while(k--){
            val = v.back();
            v.push_front(val);
            v.pop_back();
        }
        a = {v.begin(), v.end()};
    }
    
// BEST APROACH INPLACE O(N) AND O(1) SPACE
// rev first n-k elements, then last k elements rev, and then rev the entire array O(3*N)
    void rotate(vector<int> &v, int k){
        int n = v.size();
        k = k % n; //optimization if n > k, then n%k rotations is eq to k rotations
        reverse(v.begin(), v.begin() + n - k);
        reverse(v.begin() + n - k, v.end());
        reverse(v.begin(), v.end());
    }

// two vectors again O(N) and O(N) SPACE
    void rotate(vector<int> &v, int k){
        vector<int> a(v);
        int n = a.size();
        k = k %n;      
        // store the first n-k elements in array v  
        // for(int i = 0; i < n-k ; i++){
        //    v[k+i] = a[i];
        // }
        // store the last k-k elements in array v
        // for(int i = 0; i < k ; i++){
        //     v[i] = a[n-k+i];
        // }

        // same but in single loop
        int i = 0;
        while(true){
            if(i < n-k) v[k+i] = a[i];
            if (i < k) v[i] = a[n-k+i];
            if(i >= k && i >= n-k) break;
            i++;
        }

        
    }
};

// all this is for rightrotate but if u want to leftrotate then

// 12345678 and d = 2
// res = 4567812

// first d elements rev
// last n-d elemetns rev
// entire array rev

void leftRotate(int arr[], int n, int d) {
        // code here
        d = d % n;
        reverse(arr, arr + d);
        reverse(arr+d, arr+n);
        reverse(arr, arr+n);
        
    }