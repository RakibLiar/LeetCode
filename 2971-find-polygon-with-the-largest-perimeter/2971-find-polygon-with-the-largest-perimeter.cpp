class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = -1, sum = nums[0] + nums[1];
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] < sum) res = max(res, nums[i] + sum);
            sum += nums[i];
        }
        return res;
    }
};