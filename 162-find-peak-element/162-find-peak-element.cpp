class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int high = nums.size()-2, low = 1;
        while(low<=high) {
            int mid = (high+low)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) {
                return mid;
            }
            if(nums[mid] > nums[mid+1]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return 0;
    }
};