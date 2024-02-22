class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> p(n+1);
        for(vector<int> v: trust) {
            p[v[0]].second++;
            p[v[1]].first++;
        }
        int res = -1;
        for(int i=1; i<=n; i++) {
            if(p[i].second == 0 && p[i].first == n-1) {
                if(res != -1) return -1;
                res = i;
            }
        }
        return res;
    }
};