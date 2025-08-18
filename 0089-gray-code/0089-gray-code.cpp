class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0};
        for(int i=0; i<n; i++) {
            int sz = res.size(), a = (1 << i);
            for(int j=sz-1; j>=0; j--) {
                res.push_back(res[j] + a);
            }
        }
        return res;
    }
};