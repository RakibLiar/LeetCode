class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();
        int low = 0, high = R*C-1;
        while(low<=high) {
            int mid = (low+high)/2;
            int r = mid/C, c = mid%C;
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};