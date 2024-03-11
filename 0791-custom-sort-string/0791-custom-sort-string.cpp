class Solution {
public:
    string customSortString(string order, string s) {
        vector<bool> isFound(26, false);
        string res;
        for(char o: order) {
            for(char c: s) {
                if(c == o) {
                    res += c;
                    isFound[c-'a'] = true;
                }
            }
        }
        for(char c: s) {
            if(isFound[c-'a'] == false) {
                res += c;
            }
        }
        return res;
    }
};