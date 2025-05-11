class Solution {
public:
    int getMidIndex(vector<int> &nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size()-1;
        if(nums[0] < nums[n]) return 0;
        int st = 1, end = n-1, mid;
        while(st <= end) {
            mid = (st + end) / 2;
            if(nums[mid] > nums[mid+1]) {
                mid++;
                break;
            }
            if(nums[mid] > nums[n]) st = mid + 1;
            else end = mid - 1;
        }
        return mid;
    }

    int findMin(vector<int>& nums) {
        int ind = getMidIndex(nums);
        return nums[ind];
    }
};