class Solution {
public:
    long long calculateMin(vector<int> &nums, int n) {
        long long ans = 0;
        for(int a: nums) {
            ans += abs(n-a);
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), ans;
        if(len%2) {
            ans = calculateMin(nums, nums[len/2]);
        } else {
            ans = calculateMin(nums, (nums[len/2]+nums[len/2 - 1])/2);
        }
        return ans;
    }
};