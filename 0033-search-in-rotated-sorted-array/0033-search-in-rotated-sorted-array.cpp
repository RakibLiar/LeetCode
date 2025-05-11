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

    int binarySearch(vector<int> &nums, int target, int start, int end) {
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int midIndex = getMidIndex(nums);
        cout<<midIndex<<endl;
        auto ind = binarySearch(nums, target, 0, midIndex-1);
        if(ind != -1) return ind;
        ind = binarySearch(nums, target, midIndex, nums.size()-1);
        if(ind != -1) return ind;
        return -1;
    }
};