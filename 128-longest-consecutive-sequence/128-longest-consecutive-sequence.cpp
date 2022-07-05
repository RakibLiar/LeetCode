class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, bool> mp;
        for(int n: nums) {
            mp[n] = true;
        }
        auto it = mp.begin();
        int ans = 0, cnt = 1, prev = mp.begin()->first;
        for(++it; it != mp.end(); it++) {
            if(it->first == prev + 1) {
                cnt++;
            } else {
                ans = max(cnt, ans);
                cnt = 1;
            }
            prev = it->first;
        }
        return max(ans, cnt);
    }
};