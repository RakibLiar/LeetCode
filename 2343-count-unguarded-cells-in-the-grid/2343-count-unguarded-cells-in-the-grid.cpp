class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(auto wall: walls) {
            res[wall[0]][wall[1]] = 2;
        }
        for(auto guard: guards) {
            res[guard[0]][guard[1]] = 3;
        }
        vector<int> dirx{-1, 0, 1, 0};
        vector<int> diry{0, 1, 0, -1};
        for(auto guard: guards) {
            for(int i=0; i<4; i++) {
                int r = guard[0] + dirx[i], c = guard[1] + diry[i];
                while(r >=0 && r < m && c >=0 && c < n && res[r][c] < 2) {
                    res[r][c] = 1;
                    r += dirx[i];
                    c += diry[i];
                }
            }
        }
        int ret=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(res[i][j] == 0) ret++;
            }
        }
        return ret;
    }
};