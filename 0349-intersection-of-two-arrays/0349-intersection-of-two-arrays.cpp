class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(1001, 0), res;
        for(int n: nums1) {
            nums[n] = 1;
        }
        for(int n: nums2) {
            if(nums[n] == 1) {
                res.push_back(n);
                nums[n] = 0;
            }
        }
        return res;
    }
};