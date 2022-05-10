class Solution {
public:
    vector<vector<int>> result;
    void calculateResult(vector<int> v, int k, int n, int pos) {
        if(n<0) return;
        if(v.size() == k) {
            if(n==0) result.push_back(v);
            return;
        }
        for(int i=pos+1; i<=9; i++) {
            if(n-i >= 0) {
                v.push_back(i);
                calculateResult(v, k, n-i, i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        calculateResult(v, k, n, 0);
        return result;
    }
};