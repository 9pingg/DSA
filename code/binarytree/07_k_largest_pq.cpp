class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // nums.size can be greater than k, so better to add values using the function defined 
        for(int val : nums){
            add(val);
        }
    }
    
    // 2 * log(n)
    int add(int val) {
        // check if val belong in the queue or not
        if(pq.size() == k){
            pq.push(val);
            // automaticaally pops the lowest element
            pq.pop();
        }
        else{
            pq.push(val);
        }
        return pq.top();
    }
};
