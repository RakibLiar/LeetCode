class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = 0, profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] < buy) {
                buy = prices[i];
                sell = 0;
            } else if(prices[i] > sell) {
                sell = prices[i];
            }
            profit = max(profit, sell - buy);
        }
        return profit;
    }
};