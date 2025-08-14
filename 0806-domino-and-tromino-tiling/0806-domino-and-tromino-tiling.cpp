class Solution {
public:
    int numTilings(int n) {
        vector<long long> res = {0, 1, 2, 5};
        if(n <= 3) return res[n];
        for(int i=4; i<=n; i++) {
            long long x = (res[1] + 2L * res[3]) % 1000000007;
            res = {0, res[2], res[3], (int)x};
        }
        return res[3];
    }
};