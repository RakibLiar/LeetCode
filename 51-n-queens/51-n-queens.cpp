class Solution {
public:
    vector<vector<string>> result;
    bool hasQueen(vector<pair<int, int>> &pos, int row, int col) {
        for(auto p: pos) {
            if(p.first == row || p.second == col)
                return true;
            if(abs(p.first-row) == abs(p.second-col))
                return true;
        }
        return false;
    }
    void setQueens(int row, vector<pair<int, int>> &pos, int n, vector<string> &vec) {
        if(row == n) {
            result.push_back(vec);
            return;
        }
        for(int i=0; i<n; i++) {
            if(!hasQueen(pos, row, i)) {
                vec[row][i] = 'Q';
                pos.push_back({row, i});
                setQueens(row+1, pos, n, vec);
                vec[row][i] = '.';
                pos.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vec;
        vector<pair<int, int>> pos;
        string dot(n, '.');
        for(int i=0; i<n; i++) vec.push_back(dot);
        setQueens(0, pos, n, vec);
        return result;
    }
};