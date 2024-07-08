class Solution {
public:
    int findSeparatorIndex(vector<int> &nums) {
        int n = nums.size()-1;
        if(nums[0] > nums[1]) return 0;
        if(nums[n] < nums[n-1]) return n-1;
        int low = 1, high = n-1, index = 0;
        while(low < high) {
            int mid = (low + high) / 2, index = 0;
            if(nums[mid] > nums[mid+1]) return mid;
            if(nums[mid] > nums[low]) {
                low = mid;
            } else {
                index = mid;
                high = mid;
            }
        }
        return index;
    }

    int findElement(vector<int> &nums, int low, int high, int target) {
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(nums[0] == target) return 0;
            return -1;
        }
        int midIndex = findSeparatorIndex(nums);
        cout<<midIndex<<endl;
        int index = findElement(nums, 0, midIndex, target);
        if(index != -1) return index;
        index = findElement(nums, midIndex+1, nums.size()-1, target);
        if(index != -1) return index;
        return -1;
    }
};