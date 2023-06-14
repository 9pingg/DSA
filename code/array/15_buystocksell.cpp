class Solution {
public:
// O(N) similar to subarray question kadane algo
// this code is with index of buy and sell day
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        int l, r; // l = buy day, r = sell day
        for(int i = 0 ; i < prices.size() ; i++){
            if(min_price > prices[i]){
                min_price = min(min_price, prices[i]);
                l = i;
            }
            if(max_profit < prices[i] - min_price){
                max_profit = max(max_profit, prices[i] - min_price);
                r = i;
            }

        }
        return max_profit;
    }

};
// SAME BUT NO INDEX CHECK THIS FIRST

int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
