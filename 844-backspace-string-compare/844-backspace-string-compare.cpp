class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1, v2;
        for(auto c:s) {
            if(v1.size() && c == '#')
                v1.pop_back();
            else if(c != '#')
                v1.push_back(c);
        }
        for(auto c:t) {
            if(v2.size() && c == '#')
                v2.pop_back();
            else if(c != '#')
                v2.push_back(c);
        }
        return v1 == v2;
    }
};