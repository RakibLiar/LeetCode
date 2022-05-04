class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1, cnt = 0;
        sort(begin(nums), end(nums));
        while(low<high) {
            if(nums[low]+nums[high] == k) {
                low++;
                high--;
                cnt++;
            } else if(nums[low]+nums[high] > k) {
                high --;
            } else {
                low++;
            }
        }
        return cnt;
    }
};