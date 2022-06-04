class Solution {
public:
    int result;
    
    bool isValid(vector<pair<int, int>> &pos, int row, int col) {
        for(auto p: pos) {
            if(p.first == row || p.second == col)
                return false;
            if(abs(p.first-row) == abs(p.second-col))
                return false;
        }
        return true;
    }
    void setQueens(int row, vector<pair<int, int>> &pos, int n, vector<string> &vec) {
        if(row == n) {
            result++;
            return;
        }
        for(int i=0; i<n; i++) {
            if(isValid(pos, row, i)) {
                vec[row][i] = 'Q';
                pos.push_back({row, i});
                setQueens(row+1, pos, n, vec);
                vec[row][i] = '.';
                pos.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> vec;
        vector<pair<int, int>> pos;
        string dot(n, '.');
        for(int i=0; i<n; i++) vec.push_back(dot);
        setQueens(0, pos, n, vec);
        return result;
    }
};