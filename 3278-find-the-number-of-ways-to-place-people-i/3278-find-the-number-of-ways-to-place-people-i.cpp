class Solution {
public:
    bool isInside(vector<int> &left, vector<int> &right, vector<int> &mid) {
        return left[1] >= mid[1] && mid[1] >= right[1];
    }

    bool isLowerRight(vector<int> &left, vector<int> &right) {
        return left[1] >= right[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                if(isLowerRight(points[i], points[j])) {
                    int k;
                    if(j == i+1) {
                        cnt++;
                        continue;
                    }
                    for(k=i+1; k<j; k++) {
                        if(isInside(points[i], points[j], points[k])) {
                            break;
                        }
                    }
                    if(k == j) cnt++;
                }
            }
        }
        return cnt;
    }
};