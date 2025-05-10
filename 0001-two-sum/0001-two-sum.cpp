class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        unordered_map<int, vector<int>> cnt;
        int i = 0;
        for(int a: nums) {
            mp[a]++;
            cnt[a].push_back(i);
            i++;
        }

        for(auto n: mp) {
            int first = n.first;
            int second = target - first;
            if(first == second && mp[first] > 1) {
                return {cnt[first][0], cnt[second][1]};
            }
            if(first != second && mp.count(second)){
                return {cnt[first][0], cnt[second][0]};
            }
        }

        return {-1, -1};
    }
};