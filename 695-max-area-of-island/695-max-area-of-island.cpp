class Solution {
public:
    bool check(int x, int y, vector<vector<int>> &grid) {
        return 0<=x and x<grid.size() and 0<=y and y<grid[0].size();
    }
    void calculate(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &cnt) {
        vector<int> dir {0,1,0,-1,0};
        vis[x][y] = true;
        for(int i=0; i<dir.size()-1; i++) {
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            if(check(dx, dy, grid) and !vis[dx][dy] and grid[dx][dy]) {
                cnt++;
                calculate(dx, dy, grid, vis, cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0, cnt;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] && !vis[i][j]) {
                    cnt = 1;
                    calculate(i, j, grid, vis, cnt);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};