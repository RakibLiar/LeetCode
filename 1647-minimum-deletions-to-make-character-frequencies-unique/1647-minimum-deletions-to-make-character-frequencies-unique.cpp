class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char c: s) {
            v[c-'a']++;
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i=24; i>=0; i--) {
            if(v[i]>=v[i+1]) {
                int prev = v[i];
                v[i] = max(0, v[i+1]-1);
                cnt += (prev-v[i]);
            }
        }
        return cnt;
    }
};