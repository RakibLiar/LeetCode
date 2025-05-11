class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int st = i+1, ed = nums.size()-1;
            while(st < ed) {
                int s = nums[st] + nums[ed];
                if(s == -nums[i]) {
                    res.push_back({nums[i], nums[st], nums[ed]});
                    while(st < ed && nums[st] == nums[st+1]) st++;
                    while(st < ed && nums[ed] == nums[ed-1]) ed--;
                    st++;
                    ed--;
                } else if(s > -nums[i]) {
                    ed--;
                } else {
                    st++;
                }
            }
        }
        return res;
    }
};