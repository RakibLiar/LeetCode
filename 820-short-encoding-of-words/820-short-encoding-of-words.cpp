class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, bool> mp, res;
        set<string> st;
        for(string word: words) {
            st.insert(word);
        }
        for(string word: words) {
            string key;
            int n = word.size();
            for(int i=word.size()-1; i>0; i--) {
                key = word.substr(i, n-i);
                if(st.find(key) != st.end())
                    st.erase(key);
            }
        }
        int ans = 0;
        for(auto s: st) {
            ans += (s.size() + 1);
        }
        return ans;
    }
};