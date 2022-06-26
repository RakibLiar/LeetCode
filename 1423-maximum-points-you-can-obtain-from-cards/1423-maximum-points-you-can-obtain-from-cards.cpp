class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX, sum = 0;
        for(int i=0; i<n-k; i++)
            sum += nums[i];
        res = min(res, sum);
        for(int i=n-k; i<n; i++) {
            sum += (-nums[i-n+k] + nums[i]);
            if(res > sum)
                res = sum;
        }
        sum = 0;
        for(int a: nums) sum += a;
        return sum-res;
    }
};