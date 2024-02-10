class Solution {
public:
    int result(vector<int> &dp, vector<int> &arr, int pos, int k) {
        if(pos == dp.size()) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        int mx = 0, ans = 0;
        
        int last = min((int)dp.size(), pos+k);
        
        for(int i=pos; i<last; i++) {
            mx = max(mx, arr[i]);
            ans = max(ans, (i - pos + 1) * mx + result(dp, arr, i+1, k));
        }
        return dp[pos] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return result(dp, arr, 0, k);
    }
};