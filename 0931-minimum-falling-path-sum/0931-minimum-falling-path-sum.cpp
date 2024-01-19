class Solution {
public:

    /*int func(int r , int c, vector<vector<int>>& matrix) {
        if(r>= n || c>= m || r<0 || c < 0)return 1e9;
        
        if(r == n-1)return matrix[r][c];
        
        if(dp[r][c]!=-1e9)return dp[r][c];
        
        int leftDown = func(r + 1 , c - 1 , matrix);
        int rightDown = func(r+1 , c + 1, matrix);
        
        int straightDown = func(r+1,c ,matrix);
        
        return dp[r][c] = matrix[r][c] + min(leftDown, min(rightDown, straightDown));
    }*/
    
    bool check(int n, int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> tempMat(mat.begin(), mat.end());
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n; j++) {
                if(check(n, i+1, j+1)) {
                    tempMat[i+1][j+1] = dp[i+1][j+1] = min(dp[i+1][j+1], tempMat[i][j] + mat[i+1][j+1]);
                }
                if(check(n, i+1, j)) {
                    tempMat[i+1][j] = dp[i+1][j] = min(dp[i+1][j], tempMat[i][j] + mat[i+1][j]);
                }
                if(check(n, i+1, j-1)) {
                    tempMat[i+1][j-1] = dp[i+1][j-1] = min(dp[i+1][j-1], tempMat[i][j] + mat[i+1][j-1]);
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
