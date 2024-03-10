class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> nums(1001, false);
        vector<int> res;
        for(int n: nums1) {
            nums[n] = true;
        }
        for(int n: nums2) {
            if(nums[n] == true) {
                res.push_back(n);
                nums[n] = false;
            }
        }
        return res;
    }
};