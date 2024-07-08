class Solution {
public:
    int firstPosition(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, index = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) index = mid;
            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return index;
    }

    int lastPosition(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1, index = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) index = mid;
            if(nums[mid] <= target) low = mid+1;
            else high = mid-1;
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstPosition(nums, target), lastPosition(nums, target)};
    }
};