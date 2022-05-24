class SubrectangleQueries {
public:
    vector<vector<int>> rect, vect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vect.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        int ans = INT_MIN;
        for(auto v: vect) {
            if(v[0]<=row && row<=v[2] && v[1]<=col && col<=v[3]) {
                ans = v[4];
            }
        }
        return ans == INT_MIN ? rect[row][col] : ans;
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */