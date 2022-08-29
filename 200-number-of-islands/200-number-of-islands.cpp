class Solution {
public:
    int row, col;
    bool visited[305][305];
    set< pair<int,int> > st;
    bool check(int x, int y) {
        return 0<=x and x<row and 0<=y and y<col;
    }
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if(st.empty()) return;
        visited[x][y] = true;
        auto it = st.find({x, y});
        if(it != st.end())
            st.erase(it);
        if(check(x+1, y) and !visited[x+1][y] and grid[x+1][y] == '1') {
            dfs(x+1, y, grid);
        } 
        if(check(x, y+1) and !visited[x][y+1] and grid[x][y+1] == '1') {
            dfs(x, y+1, grid);
        } 
        if(check(x-1, y) and !visited[x-1][y] and grid[x-1][y] == '1') {
            dfs(x-1, y, grid);
        } 
        if(check(x, y-1) and !visited[x][y-1] and grid[x][y-1] == '1') {
            dfs(x, y-1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                visited[i][j] = false;
                if(grid[i][j] == '1') {
                    st.insert({i,j});
                }
            }
        }
        int cnt = 0;
        while(!st.empty()) {
            auto a = st.begin();
            dfs(a->first, a->second, grid);
            cnt++;
        }
        return cnt;
    }
};