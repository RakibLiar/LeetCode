class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size()-1, low = 0, mid, res = 0;
        while(low <= high) {
            mid = (low + high)/2;
            if(nums[mid] >= nums[0]) {
                low = mid+1;
            } else {
                res = mid;
                high = mid-1;
            }
        }
        return nums[res];
    }
};