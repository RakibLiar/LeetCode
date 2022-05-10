class Solution {
public:
    vector<vector<int>> result;
    void calculateSum(vector<int> v, vector<int> nums, int sum, int pos) {
        if(sum == 0) {
            result.push_back(v);
            return;
        }
        if(pos == nums.size()) return;
        for(int i=pos; i<nums.size(); i++) {
            if(sum-nums[i] < 0) return;
            if(i==pos || nums[i] != nums[i-1]) {
                v.push_back(nums[i]);
                calculateSum(v, nums, sum-nums[i], i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> v;
        calculateSum(v, nums, target, 0);
        return result;
    }
};