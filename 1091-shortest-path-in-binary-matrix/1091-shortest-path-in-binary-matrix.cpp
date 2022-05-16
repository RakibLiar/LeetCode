class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        return 0<=x && x<n && 0<=y && y<n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        vector<vector<int>> cost(n, vector<int> (n, -1));
        cost[0][0] = 1;
        queue<pair<int, int>> q;
        vector<int> dirx{0,0,1,1,1,-1,-1,-1};
        vector<int> diry{1,-1,1,0,-1,1,0,-1};
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<dirx.size(); i++) {
                int x = p.first + dirx[i];
                int y = p.second + diry[i];
                if(check(grid, x, y) && !visited[x][y] && !grid[x][y]) {
                    visited[x][y] = true;
                    cost[x][y] = cost[p.first][p.second] + 1;
                    q.push({x,y});
                }
            }
        }
        return cost[n-1][n-1];
    }
};