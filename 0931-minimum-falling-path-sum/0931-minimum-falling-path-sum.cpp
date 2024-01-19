class Solution {
public:
    bool check(int n, int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> tempMat(mat.begin(), mat.end());
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n; j++) {
                for(int k=-1; k<=1; k++) {
                    if(check(n, i+1, j+k)) {
                        tempMat[i+1][j+k] = dp[i+1][j+k] = min(dp[i+1][j+k], tempMat[i][j] + mat[i+1][j+k]);
                    }
                }
            }
        }
        int res = INT_MAX;
        
        for(int i=0; i<n; i++) {
            res = min(res, tempMat[n-1][i]);
        }
        return res;
    }
};
