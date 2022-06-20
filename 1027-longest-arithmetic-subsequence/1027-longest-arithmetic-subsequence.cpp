class Solution {
public:
    //unordered_map<int, map<int,int> > mp;
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 2;
        vector<vector<int>> mp(1005, vector<int>(1005, -1));
        for(int i=0; i<nums.size(); i++) {
            for(int j = i-1; j>=0; j--) {
                int a = nums[i] - nums[j] + 500;
                mp[i][a] = mp[j][a] != -1 ? max(mp[j][a]+1, mp[i][a]) : max(mp[i][a], 2);
                ans = max(ans,mp[i][a]);
            }
        }
        return ans;
    }
};