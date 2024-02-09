class Solution {
public:
    void sieve(vector<bool> &prime, int n) {
        prime[0] = prime[1] = false;
        for(int i=4; i<=n; i+=2) prime[i] = false;
        for(int i=9; i<=n; i+=6) prime[i] = false;
        for(int i=5; i*i<=n; i+=2) {
            if(prime[i] == true) {
                for(int j=i*i; j<=n; j += 2*i) {
                    prime[j] = false;
                }
            }
        }
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n+1, true);
        sieve(prime, n);
        vector<vector<int>> res;
        for(int i=2; i<=n/2; i++) {
            if(prime[i] && prime[n-i]) {
                res.push_back({i, n-i});
            }
        }
        return res;
    }
};