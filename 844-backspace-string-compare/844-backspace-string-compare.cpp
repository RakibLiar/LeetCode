class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1,v2;
        for(auto c: s) {
            if(c == '#' && !v1.empty())
                v1.pop_back();
            else if(c != '#')
                v1.push_back(c);
        }
        for(auto c: t) {
            if(c == '#' && !v2.empty())
                v2.pop_back();
            else if(c != '#')
                v2.push_back(c);
        }
        return v1 == v2;
    }
};