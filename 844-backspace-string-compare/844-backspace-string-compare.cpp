class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v, v2;
        for(auto c:s) {
            if(v.size() && c == '#')
                v.pop_back();
            else if(c != '#')
                v.push_back(c);
        }
        for(auto c:t) {
            if(v2.size() && c == '#')
                v2.pop_back();
            else if(c != '#')
                v2.push_back(c);
        }
        return v == v2;
    }
};