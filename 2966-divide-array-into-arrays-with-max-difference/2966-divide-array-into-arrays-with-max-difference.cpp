class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int a: nums) {
            cout<<a<<" ";
        }
        cout<<endl;
        for(int i=0; i<nums.size(); i+=3) {
            cout<<nums[i]<<" "<<nums[i+1]<<" "<<nums[i+2]<<endl;
            if(nums[i] + k < nums[i+2])
                return {};
            else
                res.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return res;
    }
};