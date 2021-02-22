class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > min) {
                profit = max(profit, prices[i] - min);
            } else {
                min = prices[i];
            }
        }
        return profit;
    }
}; 