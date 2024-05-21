class Solution {
public:
    void calculate(vector<vector<int>> &result, vector<int> &nums, vector<int> &temp, int pos) {
        for(int i=pos; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            calculate(result, nums, temp, i+1);
            temp.pop_back();
        }
        result.push_back(temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        calculate(result, nums, temp, 0);
        return result;
    }
};