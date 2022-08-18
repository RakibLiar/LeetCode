class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v(100001, 0);
        for(int a: arr) {
            v[a]++;
        }
        sort(v.begin(), v.end(), greater<int>());
        int n = arr.size(), ans = 0, cnt = 0;
        for(int i=0; ans < n/2; i++) {
            ans += v[i];
            cnt++;
        }
        return cnt;
    }
};