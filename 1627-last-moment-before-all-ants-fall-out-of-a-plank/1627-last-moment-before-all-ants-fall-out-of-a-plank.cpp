class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(int a: left) {
            res = max(res, a);
        }
        for(int a: right) {
            res = max(res, n-a);
        }
        return res;
    }
};