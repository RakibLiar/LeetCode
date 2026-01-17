class Solution {
public:
    bool isInside(int bottomX, int bottomY,int topX,int topY,vector<int> &left,vector<int> &right) {
        if(left[0] <= bottomX && bottomX <= right[0] && left[1] <= bottomY && bottomY <= right[1]) {
            if(left[0] <= topX && topX <= right[0] && left[1] <= topY && topY <= right[1]) {
                return true;
            }
        }
        return false;
    }

    long long findSquare(vector<int> &left1, vector<int> &right1, vector<int> &left2, vector<int> &right2) {
        long long bottomX = max(left1[0], left2[0]);
        long long bottomY = max(left1[1], left2[1]);
        long long topX = min(right1[0], right2[0]);
        long long topY = min(right1[1], right2[1]);
        if(isInside(bottomX, bottomY, topX, topY, left1, right1) && isInside(bottomX, bottomY, topX, topY, left2, right2)) {
            long long x = abs(bottomX - topX);
            long long y = abs(bottomY - topY);
            long long len = min(x,y);
            return len * len;
        }
        return 0;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        for(int i=0; i<bottomLeft.size(); i++) {
            for(int j=i+1; j<topRight.size(); j++) {
                ans = max(ans, findSquare(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }
        return ans;
    }
};