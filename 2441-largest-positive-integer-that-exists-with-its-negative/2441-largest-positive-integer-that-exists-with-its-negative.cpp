class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int left = 0, right = nums.size()-1; nums[left] < 0 && nums[right] > 0; ) {
            if(-nums[left] == nums[right]) return nums[right];
            if(-nums[left] > nums[right]) left++;
            else right--;
        }
        return -1;
    }
};