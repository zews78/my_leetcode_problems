class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int profit = 0;

        for(auto x: prices){
            if(x>min_val){
                profit = max(profit, x-min_val);
            }else{
                min_val = x;
            }
        }

        return profit;
    }
};