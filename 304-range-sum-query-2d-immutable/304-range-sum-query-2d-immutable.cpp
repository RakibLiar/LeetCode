class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        sumMat = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix.size(); i++) {
            int sum = 0;
            for(int j=0; j<matrix[i].size(); j++) {
                sum += matrix[i][j];
                sumMat[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int cumsum = 0;
        for(int i=row1; i<=row2; i++) {
            int sum = 0;
            if(col1>0) sum = sumMat[i][col1-1];
            cumsum += (sumMat[i][col2]-sum);
        }
        return cumsum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */