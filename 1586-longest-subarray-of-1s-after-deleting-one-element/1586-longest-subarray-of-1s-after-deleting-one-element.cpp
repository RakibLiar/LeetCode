class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        int zero = 0, one = 0;
        for(int n: nums) {
            if(n == 0) {
                if(one != 0) {
                    v.push_back(one);
                }
                one = 0;
                v.push_back(0);
            } else {
                one++;
            }
        }
        if(one != 0) {
            v.push_back(one);
        }
        if(v.size() == 1) return v[0] == 0 ? 0 : v[0] - 1;
        if(v.size() == 2) return v[0] + v[1];
        int res = 0;
        for(int i=0; i<v.size() - 2; i++) {
            res = max(res, v[i] + v[i+2]);
            res = max(res, v[i+1]);
        }
        return res;
    }
};