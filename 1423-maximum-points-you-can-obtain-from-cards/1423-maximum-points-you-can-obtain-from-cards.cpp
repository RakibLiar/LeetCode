class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        for(int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
            suffix[n-i] = suffix[n-i+1] + nums[n-i];
        }
        for(int i=0; i<=k; i++) {
            res = max(res, prefix[i] + suffix[n-k+i]);
        }
        return res;
    }
};