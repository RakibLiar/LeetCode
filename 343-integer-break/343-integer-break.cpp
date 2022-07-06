class Solution {
public:
    int integerBreak(int n) {
        int res = INT_MIN;
        for(int i=2; i<=n; i++) {
            int div = n/i, rem = n%i;
            int ans = round(pow(div, i-rem)) * round(pow(div+1, rem));
            res = max(ans, res);
        }
        return res;
    }
};