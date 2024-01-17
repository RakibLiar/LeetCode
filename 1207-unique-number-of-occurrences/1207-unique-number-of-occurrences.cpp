class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_map<int, bool> checkMp;
        for(int a: arr) {
            mp[a]++;
        }
        for(auto it: mp) {
            if(checkMp.count(it.second)) return false;
            checkMp[it.second] = true;
        }
        return true;
    }
};