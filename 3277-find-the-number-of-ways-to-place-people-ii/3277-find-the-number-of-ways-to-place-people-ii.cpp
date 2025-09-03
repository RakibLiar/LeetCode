class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        for(int i=0; i<points.size(); i++) {
            int lastY = INT_MIN;
            for(int j=i+1; j<points.size(); j++) {
                if(points[i][1] >= points[j][1] &&  points[j][1] > lastY) {
                    lastY = points[j][1];
                    cnt++;
                }
            }
        }
        return cnt;
    }
};