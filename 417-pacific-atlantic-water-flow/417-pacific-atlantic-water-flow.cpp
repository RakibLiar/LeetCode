class Solution {
public:
    bool check(vector<vector<int>> &ht, int x, int y) {
        return 0<=x && x<ht.size() && 0<=y && y<ht[0].size();
    }
    void dfs(vector<vector<int>> &ht, vector<vector<bool>> &visited, int x, int y) {
        if(visited[x][y]) return;
        visited[x][y] = true;
        vector<int> dir {0,1,0,-1,0};
        for(int i=0; i<dir.size()-1; i++) {
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            if(check(ht, dx, dy) && !visited[dx][dy] && ht[dx][dy] >= ht[x][y]) {
                dfs(ht, visited, dx,dy);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        int row = ht.size(), col = ht[0].size();
        vector<vector<bool>> P(row, vector<bool>(col, false)), A(row, vector<bool>(col, false));
        for(int i=0; i<col; i++) {
            dfs(ht, P, 0, i);
            dfs(ht, A, row-1, i);
        }
        for(int i=0; i<row; i++) {
            dfs(ht, P, i, 0);
            dfs(ht, A, i, col-1);
        }
        vector<vector<int>> res;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(P[i][j] && A[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};