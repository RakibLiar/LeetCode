class Solution {
public:
    long long MOD = 1000000007;
    long long power(long long b) {
        long long p = MOD-2, res = 1;
        while(p) {
            if(p&1) res = (res*b)%MOD;
            b = (b*b)%MOD;
            p >>= 1;
        }
        return res;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        if(endPos - startPos > k || (k+startPos-endPos)%2 != 0) return 0;
        int L = (k+startPos-endPos)/2, R = endPos-startPos+L;
        int total = L+R;
        vector<long long> fact(total+1, 1);
        for(int i=1; i<=total; i++) {
            fact[i] = (i*fact[i-1])%MOD;
        }
        int lv = power(fact[L]);
        int rv = power(fact[R]);
        long long res = fact[total];
        res = (res*lv)%MOD;
        res = (res*rv)%MOD;
        return (int)res;
    }
};