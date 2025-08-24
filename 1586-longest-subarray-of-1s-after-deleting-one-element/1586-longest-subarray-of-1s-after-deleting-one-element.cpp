class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, start = 0, zero = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) zero++;

            while(zero > 1) {
                if(nums[start++] == 0) zero--;
            }

            res = max(res, i - start);
        }
        return res;
    }
};