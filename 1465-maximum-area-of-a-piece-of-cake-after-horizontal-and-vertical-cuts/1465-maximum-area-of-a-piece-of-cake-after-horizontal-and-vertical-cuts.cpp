class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long a = 0, b = 0, prevh = 0, prevv = 0;
        for(int n: verticalCuts) {
            b = max(b, n-prevv);
            prevv = n;
        }
        for(int n: horizontalCuts) {
            a = max(a, -prevh+n);
            prevh = n;
        }
        return (a*b) % 1000000007;
    }
};