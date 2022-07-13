class Solution {
public:
    int calculate(vector<int> &nums) {
        stack<pair<int,int>> st;
        st.push({-1, -1});
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            while(st.top().first >= nums[i]) {
                auto t = st.top();
                st.pop();
                ans = max(ans, min((i-st.top().second-1), t.first));
            }
            st.push({nums[i], i});
        }
        while(st.size()>1) {
            auto t = st.top();
            st.pop();
            ans = max(ans, min( (int)(nums.size() - st.top().second-1), t.first));
        }
        return ans*ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>>nums(row, vector<int>(col, 0));
        for(int i=0; i<col; i++) nums[0][i] = matrix[0][i] - '0';
        for(int i=1; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '1') {
                    nums[i][j] += (nums[i-1][j] + 1);
                }
            }
        }
        int ans = 0;
        for(auto v: nums) {
            ans = max(ans, calculate(v));
        }
        return ans;
    }
};