class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for(int left = 0; left<col; left++) {
            vector<int> sum(row, 0);
            for(int right = left; right<col; right++) {
                for(int i=0; i<row; i++) {
                    sum[i] += matrix[i][right];
                }
                set<int> st;
                st.insert(0);
                int curSum = 0, maxSum = INT_MIN;
                for(int s: sum) {
                    curSum += s;
                    auto it = st.lower_bound(curSum-k);
                    if(it != st.end()) maxSum = max(maxSum, curSum - (*it));
                    st.insert(curSum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};