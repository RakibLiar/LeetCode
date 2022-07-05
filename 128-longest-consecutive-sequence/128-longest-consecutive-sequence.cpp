class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, bool> mp;
        for(int n: nums) {
            mp[n] = true;
        }
        auto it = mp.begin(), prev = mp.begin();
        int ans = 0, cnt = 1;
        for(++it; it != mp.end(); it++) {
            if(it->first == prev->first + 1) {
                cnt++;
            } else {
                ans = max(cnt, ans);
                cnt = 1;
            }
            prev = it;
        }
        return max(ans, cnt);
    }
};