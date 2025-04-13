class Solution {
public:
    long long MOD = 1000000007;
    int bigMod(long long b, long long p) {
        long long res = 1;
        while(p) {
            if(p&1) res = (res * b) % MOD;
            b = (b * b) % MOD;
            p /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long a = (n+1)/2, b = n / 2;
        long long r1 = bigMod(5, a);
        long long r2 = bigMod(4, b);
        long long res = (r1 * r2) % MOD;
        return res;
    }
};