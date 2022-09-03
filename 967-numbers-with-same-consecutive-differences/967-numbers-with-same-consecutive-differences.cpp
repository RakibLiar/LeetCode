class Solution {
public:
    void result(int total, int dif, int isFirst, int cur, int prev, int cnt, vector<int> &ans) {
        if(cnt == total) {
            ans.push_back(cur);
            return;
        }
        for(int i=isFirst; i<=9; i++) {
            if(isFirst == 1) {
                result(total, dif, 0, i, i, cnt+1, ans);
            } else if (abs(prev-i) == dif) {
                result(total, dif, 0, 10*cur+i, i, cnt+1, ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        result(n, k, 1, 0, 0, 0, ans);
        return ans;
    }
};