class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        int f1 = 1, f2 = 2, res;
        for(int i=3; i<=n; i++) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;
    }
};