#include <bits/stdc++.h>
using namespace std;

// basic appraoch use sorting, gives tle
vector<int> res;
// o(N*log(n))
void addNum(int num) {
    res.push_back(num);
    sort(res.begin(), res.end());
}
// o(1)
double findMedian() {
    int n = res.size();
    if (n % 2 == 0){
        // notice to get the middle elements: if even use n-1 / 2 and n / 2
        return (double)(res[(n-1)/2] + res[n/2]) / 2.0;
    }else{
        // if size is not even then use n/2
        return res[n/2];
    }
}
// better appraoch we can keep teh array sorted by finding out where to insert the element by looping and noting the pos
// then insertin the element at that positoin o(n)+o(n)
// to find position of where to insert, we can use lower_bound as arr is sorted so total complexity o(log(n)) + o(n)
// this still gives tle

vector<int> res;
// o(N + log(n))
void addNum(int num) {
    auto pos = lower_bound(res.begin(), res.end(), num);
    res.insert(pos, num);        
}

double findMedian() {
    int n = res.size();
    if (n % 2 == 0){
        return (double)(res[(n-1)/2] + res[n/2]) / 2.0;
    }else{
        return res[n/2];
    }
}

// one more appraoch is to use: multiset or binary search tree. so add becomes o(log(n)) but the findmedian becomes o(n/2)
// as we have to itr the set. this doesnt give tle

// OPTIMAL APPROACH: basically use two queues max pq and min pq.
class MedianFinder {
public:
    priority_queue<int> max_pq; // has the lower half of arr
    priority_queue<int, vector<int>, greater<int>> min_pq; // upper half of the arr
    MedianFinder() {
        
    }
    // try to keep the elements eq in both the heaps, but queues may differ by 1 element but thats fine
    // dont let teh size diff be more than 1
    // 2 push 1 pop = 3 * log(n) (number of push and pops matter)
    void addNum(int num) {
        // remember max_pq holds lower k digits, so if number is less that top of max_pq then store it here
        if(max_pq.size() == 0 or max_pq.top() > num){
            max_pq.push(num);    
        }else{ // else store it in min_pq
            min_pq.push(num);
        }

        // if size of max queue greater than other by 2, we need to equalize them
        if(max_pq.size() > min_pq.size() + 1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else if (max_pq.size() + 1 < min_pq.size() ){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    // O(1)
    double findMedian() {
        // if even elements avg them out
        if(max_pq.size() == min_pq.size()){
            return (double)(max_pq.top() + min_pq.top()) / 2.0;
        }else{
            // which ever has more elements send that
            return max_pq.size() > min_pq.size() ? max_pq.top() : min_pq.top();
        }
    }
};
