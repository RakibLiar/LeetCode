class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> temp(100005, 0);
        for(int a: nums) {
            temp[a]++;
        }
        int ind = -1;
        for(int i=1; i<=100000; i++) {
            for(int j=0; j<temp[i]; j++) {
                nums[++ind] = i;
            }
        }
        for(int i=0; i<nums.size(); i+=3) {
            if(nums[i] + k < nums[i+2])
                return {};
            else
                res.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return res;
    }
};