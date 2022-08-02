class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        priority_queue<int> pq;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(pq.size() >= k && matrix[i][j] >= pq.top())
                    break;
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};