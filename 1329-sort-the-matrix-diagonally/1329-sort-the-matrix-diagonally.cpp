class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0; i<mat[0].size(); i++) {
            vector<int> v;
            for(int c=i, r=0; c<mat[0].size() && r<mat.size(); c++, r++) {
                v.push_back(mat[r][c]);
            }
            sort(v.begin(), v.end());
            for(int c=i, r=0, j=0; c<mat[0].size() && r<mat.size() && j<v.size(); c++, r++, j++) {
                mat[r][c] = v[j];
            }
        }
        for(int i=1; i<mat.size(); i++) {
            vector<int> v;
            for(int c=0, r=i; c<mat[0].size() && r<mat.size(); c++, r++) {
                v.push_back(mat[r][c]);
            }
            sort(v.begin(), v.end());
            for(int c=0, r=i, j=0; j<v.size() && c<mat[0].size() && r<mat.size(); c++, r++, j++) {
                mat[r][c] = v[j];
            }
        }
        return mat;
    }
};