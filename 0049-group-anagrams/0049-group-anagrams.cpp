class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s: strs) {
            string temp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
        }
        for(auto it: mp) {
            res.push_back(it.second);
        }
        return res;
    }
};