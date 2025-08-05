class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> cumSum, res;
        long long sum = 0;
        for(long long a: nums) {
            sum += a;
            cumSum.push_back(sum);
        }
        
        for(int q: queries) {
            long long ans = 0;
            long long midIndex = upper_bound(nums.begin(), nums.end(), q) - nums.begin() - 1;
            
            if(midIndex >= 0 && midIndex < nums.size()) {
                ans = q * (midIndex + 1) - cumSum[midIndex];
            }
            long long rightCount = nums.size() - midIndex - 1;
            if(rightCount > 0) {
                long long s = cumSum.back();
                if(rightCount < nums.size()) s -= cumSum[cumSum.size() - rightCount - 1];
                ans += s - q * rightCount;
            }
            
            res.push_back(ans);
        }
        return res;
    }
};