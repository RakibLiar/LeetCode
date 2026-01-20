class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int n: nums) {
            int i=0;
            for(i=1; i<n; i++) {
                if((i | (i+1)) == n) {
                    res.push_back(i);
                    break;
                }
            }
            if(i == n) res.push_back(-1);
        }
        return res;
    }
};