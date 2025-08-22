class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minR = INT_MAX, maxR = -1, minC = INT_MAX, maxC = -1;
        int row = grid.size(), col = grid[0].size();
        for(int r=0; r<row; r++) {
            for(int c=0; c<col; c++) {
                if(grid[r][c] == 1) {
                    minR = min(minR, r);
                    maxR = max(maxR, r);
                    minC = min(minC, c);
                    maxC = max(maxC, c);
                }
            }
        }
        
        int lenR = maxR - minR + 1;
        int lenC = maxC - minC + 1;
        return lenR * lenC;
    }
};