class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), comp);
        int cnt = 0, sz = prop.size();
        auto high = prop[sz-1][1];
        for(int i=sz-1; i>=0; i--) {
            int a = prop[i][1];
            cnt += (a<high);
            high = max(high, a);
        }
        return cnt;
    }
};