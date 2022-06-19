class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, vector<string>> mp;
        for(string s: products) {
            int len = s.size();
            string k = "";
            for(int i=0; i<len; i++) {
                k += s[i];
                mp[k].push_back(s);
            }
        }
        string k = "";
        vector<vector<string>> ans;
        for(int i=0; i<searchWord.size(); i++) {
            k += searchWord[i];
            vector<string> v;
            int l = mp[k].size();
            sort(mp[k].begin(), mp[k].end());
            for(int j=0; j<min(3, l); j++) {
                v.push_back(mp[k][j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};