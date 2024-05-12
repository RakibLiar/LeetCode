class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2));
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<n-1; j++) {
                int mx = INT_MIN;
                for(int r = i-1; r <= i+1; r++) {
                    for(int c = j-1; c <= j+1; c++) {
                        mx = max(grid[r][c], mx);
                    }
                }
                result[i-1][j-1] = mx;
            }
        }
        return result;
    }
};