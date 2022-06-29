class Solution {
public:
    vector<string> digit_map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> cartisianProduct(vector<string> &v, string s) {
        vector<string> res;
        for(auto s1: v) {
            for(auto c: s) {
                res.push_back(s1+c);
            }
        }
        return res;
    }
    vector<string> letterCombinations(string digits, int pos = 0) {
        if(!digits.size()) return {};
        vector<string> res{""};
        for(auto c: digits) {
            res = cartisianProduct(res, digit_map[c-'0']);
        }
        return res;
    }
};