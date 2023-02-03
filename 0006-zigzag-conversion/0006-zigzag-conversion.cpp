class Solution {
public:
    string convert(string s, int row) {
        if(row <= 1) return s;
        int j = 0, dir = -1;
        vector<string> v(row);
        for(int i=0; i<s.size(); i++) {
            if(j == 0 || j == row-1) dir *= (-1);
            v[j].push_back(s[i]);
            j += dir;
        }
        string res;
        for(string str: v) {
            res += str;
        }
        return res;
    }
};