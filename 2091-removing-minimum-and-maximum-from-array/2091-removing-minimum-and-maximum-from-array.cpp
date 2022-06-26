class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int mx = INT_MIN, mn = INT_MAX, mni, mxi, res = INT_MAX, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > mx) {
                mx = nums[i];
                mxi = i;
            }
            if(nums[i] < mn) {
                mn = nums[i];
                mni = i;
            }
        }
        res = min(res, max(mxi,mni) + 1);
        res = min(res, mxi + 1 + n-mni);
        res = min(res, mni + 1 + n-mxi);
        res = min(res, max(n-mni, n-mxi));
        return res;
    }
};