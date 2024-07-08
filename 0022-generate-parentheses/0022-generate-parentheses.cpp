class Solution {
public:
    void generate(vector<string> &res, string s, int open, int close, int n) {
        if(open > n || close > n || close > open) return;
        if(open == n && close == n) {
            res.push_back(s);
        }
        generate(res, s+"(", open + 1, close, n);
        generate(res, s+")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
};