class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int row = mat.size(), col = mat[0].size();
        for(int i=0; i < row+col-1 ; i++) {
            int r, c, dif;
            if(i&1) {
                c = min(i, col-1);
                r = max(i-col+1, 0);
                dif = 1;
            } else {
                r = min(i, row-1);
                c = max(i-row+1, 0);
                dif = -1;
            }
            cout<<i<<" "<<r<<" "<<c<<endl;
            while(0<=r && r<row && 0<=c && c<col) {
                res.push_back(mat[r][c]);
                r += dif;
                c -= dif;
            }
        }
        return res;
    }
};