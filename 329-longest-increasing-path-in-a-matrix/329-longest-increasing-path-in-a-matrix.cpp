class Solution {
public:
    bool check(vector<vector<int>>& matrix, int r, int c) {
        return 0<=r && r<matrix.size() && 0<=c && c<matrix[0].size();
    }
    void bfs(vector<vector<int>> &level, vector<vector<int>> &matrix, int x_pos, int y_pos) {
        queue<pair<int, int>> q;
        q.push({x_pos, y_pos});
        level[x_pos][y_pos] = 1;
        vector<int> dir {0,1,0,-1,0};
        while(!q.empty()) {
            auto par = q.front();
            q.pop();
            for(int i=0; i<dir.size()-1; i++) {
                int x = par.first + dir[i];
                int y = par.second + dir[i+1];
                if(check(matrix, x, y) && matrix[par.first][par.second] > matrix[x][y] && level[par.first][par.second] + 1 > level[x][y]) {
                    level[x][y] = level[par.first][par.second]+1;
                    q.push({x, y});
                }
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> level(row, vector<int>(col, 0));
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(level[i][j] == 0) {
                    bfs(level, matrix, i, j);
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++)
                ans = max(ans, level[i][j]);
        }
        return ans;
    }
};