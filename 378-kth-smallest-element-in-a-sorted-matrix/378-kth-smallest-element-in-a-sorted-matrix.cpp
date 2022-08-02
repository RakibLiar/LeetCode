class Solution {
public:
    bool check(int x, int y, int n) {
        return 0<=x and x<n and 0<=y and y<n;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), cnt = 0, ans = matrix[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({matrix[0][0], 0, 0});
        vector<vector<bool>> test(n, vector<bool>(n, false));
        while(true) {
            vector<int> v = pq.top();
            pq.pop();
            cnt++;
            //cout<<cnt<<" "<<v[0]<<endl;
            if(cnt == k) {
                ans = v[0];
                break;
            }
            int x = v[1], y = v[2];
            if(check(x+1, y, n) && !test[x+1][y]) {
                pq.push({matrix[x+1][y], x+1, y});
                test[x+1][y] = true;
            }
            if(check(x, y+1, n) && !test[x][y+1]) {
                pq.push({matrix[x][y+1], x, y+1});
                test[x][y+1] = true;
            }
        }
        return ans;
    }
};