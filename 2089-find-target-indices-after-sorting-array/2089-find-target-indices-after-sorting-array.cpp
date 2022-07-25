class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(binary_search(nums.begin(), end(nums), target) == false)
            return {};
        int low = lower_bound(begin(nums),end(nums), target) - begin(nums);
        int upper = upper_bound(begin(nums), end(nums), target) - begin(nums);
        vector<int> res;
        for(int i=low; i<upper; i++)
            res.push_back(i);
        return res;
    }
};