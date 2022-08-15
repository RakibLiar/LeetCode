class Solution {
public:
    vector<string> res;
    void generate(int n, int first, int second, string s) {
        if(first > n || second > n || second > first) return;
        if(first == n && second == n) {
            res.push_back(s);
            return;
        }
        generate(n, first+1, second, s+"(");
        generate(n, first, second+1, s+")");
    }
    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return res;
    }
};