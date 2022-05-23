class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int n: nums) {
            if(mp.count(n)) {
                return true;
            }
            mp[n] = true;
        }
        return false;
    }
};