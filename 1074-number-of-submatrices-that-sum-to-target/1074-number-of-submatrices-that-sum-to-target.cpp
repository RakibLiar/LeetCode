class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int cnt = 0, row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> colSum(row, vector<int>(col, 0)), totalSum(row, vector<int>(col, 0));
        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                colSum[j][i] = matrix[j][i] + ((j>0) ? colSum[j-1][i] : 0);
            }
        }
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                totalSum[i][j] = colSum[i][j] + ((j>0) ? totalSum[i][j-1] : 0);
            }
        }
        for(int x1=0; x1<row; x1++) {
            for(int y1=0; y1<col; y1++) {
                for(int x2=x1; x2<row; x2++) {
                    for(int y2=y1; y2<col; y2++) {
                        int a = totalSum[x2][y2] - ((x1 > 0) ? totalSum[x1-1][y2] : 0) - ((y1 > 0) ? totalSum[x2][y1-1] : 0) + ((x1 > 0 and y1) > 0 ? totalSum[x1-1][y1-1] : 0);
                        if(a == target)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};