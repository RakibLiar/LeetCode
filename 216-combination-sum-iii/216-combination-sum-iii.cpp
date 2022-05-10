class Solution {
public:
    vector<vector<int>> result;
    void calculateResult(vector<int> v, vector<int> digit, int k, int n, int pos) {
        if(n<0) return;
        if(v.size() == k) {
            if(n==0) result.push_back(v);
            return;
        }
        for(int i=pos+1; i<=9; i++) {
            if(!digit[i] && n-i >= 0) {
                digit[i] = true;
                v.push_back(i);
                calculateResult(v, digit, k, n-i, i);
                digit[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v, digit(10, false);
        calculateResult(v, digit, k, n, 0);
        return result;
    }
};