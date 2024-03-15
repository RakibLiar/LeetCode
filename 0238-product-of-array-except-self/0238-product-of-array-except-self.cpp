class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fv(n, 1), bv(n, 1), res(n, 1);
        fv[0] = nums[0];
        for(int i=1; i<n-1; i++) {
            fv[i] = fv[i-1] * nums[i];
        }
        bv[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            bv[i] = bv[i+1] * nums[i];
        }
        for(int i=0; i<n; i++) {
            if(i == 0) {
                res[i] = bv[i+1];
            } else if(i == n-1) {
                res[i] = fv[i-1];
            } else {
                res[i] = bv[i+1] * fv[i-1];
            }
        }
        return res;
    }
};