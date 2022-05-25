class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, prev = prices[0];
        for(int a: prices) {
            ans = max(a-prev, ans);
            prev = min(a, prev);
        }
        return ans;
    }
};