class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> cumsum(row+1, vector<int>(col+1, 0));

        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                cumsum[i][j] = mat[i-1][j-1] + cumsum[i-1][j] + cumsum[i][j-1] - cumsum[i-1][j-1];
            }
        }

        int mx = min(row, col);
        while(mx > 0) {
            for(int i=0; i+mx<=row; i++) {
                for(int j=0; j+mx<=col; j++) {
                    int sum = cumsum[i+mx][j+mx] - cumsum[i][j+mx] - cumsum[i+mx][j] + cumsum[i][j];
                    if(sum <= threshold) return mx;
                }
            }
            mx--;
        }
        return 0;
    }
};