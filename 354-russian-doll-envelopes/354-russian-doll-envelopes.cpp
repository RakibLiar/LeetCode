class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), comp);
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i][1];
            int ind = lower_bound(v.begin(), v.end(), a) - v.begin();
            if(ind>=v.size()) v.push_back(a);
            else v[ind] = a;
        }
        return v.size();
    }
};