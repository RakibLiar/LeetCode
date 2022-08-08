class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int x: nums) {
            auto upper = lower_bound(res.begin(), res.end(), x);
            if(upper == res.end()) {
                res.push_back(x);
            } else {
                int ind = upper - res.begin();
                res[ind] = x;
            }
        }
        return res.size();
    }
};