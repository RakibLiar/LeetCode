class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int i=1; i<grid[0].size(); i++) {
            vector<int> v;
            for(int j=0, k=i; k<grid[0].size(); j++, k++) {
                v.push_back(grid[j][k]);
            }
            sort(v.begin(), v.end());
            for(int j=0, k=i, ind = 0; k<grid[0].size(); j++, k++, ind++) {
                grid[j][k] = v[ind];
            }
        }

        for(int i=0; i<grid.size(); i++) {
            vector<int> v;
            for(int j=i, k=0; j<grid.size(); j++, k++) {
                v.push_back(grid[j][k]);
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            for(int j=i, k=0, ind = 0; j<grid.size(); j++, k++, ind++) {
                grid[j][k] = v[ind];
            }
        }
        return grid;
    }
};