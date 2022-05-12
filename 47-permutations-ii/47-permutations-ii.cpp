class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        do
        {
            result.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};