class Solution {
public:
    int calculate(vector<vector<int>> &dp, vector<int> &v, int pos, int n) {
        if(n == 0) {
            //cout<<pos<<" "<<n<<endl;
            return 1;
        }
        if(pos >= v.size() || n < 0) {
            //cout<<pos<<" "<<n<<endl;
            return 0;
        }

        if(dp[pos][n] != -1) return dp[pos][n];
        int a = 0;
        a += calculate(dp, v, pos+1, n-v[pos]);
        a %= 1000000007;
        a += calculate(dp, v, pos+1, n);
        a %= 1000000007;
        return dp[pos][n] = a;
    }

    int numberOfWays(int n, int x) {
        vector<int> numbers;
        for(int i=1; ; i++) {
            int a = pow(i, x) + 0.001;
            if(a > n) break;
            numbers.push_back(a);
        }
        vector<vector<int>> dp(numbers.size(), vector<int>(n+1, -1));
        return calculate(dp, numbers, 0, n);
    }
};