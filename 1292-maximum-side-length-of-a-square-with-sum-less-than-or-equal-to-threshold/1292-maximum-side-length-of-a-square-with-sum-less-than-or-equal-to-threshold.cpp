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

        int high = min(row, col), ans = 0, low = 0;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            bool ok = false;
            for(int i=0; i+mid<=row; i++) {
                for(int j=0; j+mid<=col; j++) {
                    int sum = cumsum[i+mid][j+mid] - cumsum[i][j+mid] - cumsum[i+mid][j] + cumsum[i][j];
                    if(sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};