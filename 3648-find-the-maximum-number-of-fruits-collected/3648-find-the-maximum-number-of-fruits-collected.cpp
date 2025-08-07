/*

(1, 0), 2, 1), (3, 2)

*/

class Solution {
public:
    long long calculate(vector<vector<int>> &dp, vector<vector<int>> &fruits, int x, int y, int n) {
        if(x >= y) return 0;
        if(x>=n || x<0 || y>=n || y<0) return 0;
        if(x == n) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = max({calculate(dp, fruits, x+1, y-1, n), calculate(dp, fruits, x+1, y, n), calculate(dp, fruits, x+1, y+1, n)}) + fruits[x][y];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        long long a = 0;
        
        for(int i=0; i<n; i++) a += fruits[i][i];
        for (int pass = 0; pass < 2; pass++) {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(fruits[i][j], fruits[j][i]);
                }
            }
            a += calculate(dp, fruits, 0, n-1, n);
        }
        return a;
    }
};