class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
        if(grid[0][0]) return 0;
        path[0][0] = 1;
        for(int i=1; i<grid[0].size(); i++) {
            if(grid[0][i])
                path[0][i] = 0;
            else
                path[0][i] += path[0][i-1];
        }
        for(int i=1; i<grid.size(); i++) {
            if(grid[i][0])
                path[i][0] = 0;
            else
                path[i][0] += path[i-1][0];
        }
        for(int i=1; i<grid.size(); i++) {
            for(int j=1; j<grid[0].size(); j++) {
                if(grid[i][j])
                    path[i][j] = 0;
                else
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[grid.size()-1][grid[0].size()-1];
    }
};