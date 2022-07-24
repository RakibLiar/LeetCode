class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), r = row-1, c = 0;
        while(r>=0 && c<col) {
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] > target)
                r--;
            else
                c++;
        }
        return false;
    }
};