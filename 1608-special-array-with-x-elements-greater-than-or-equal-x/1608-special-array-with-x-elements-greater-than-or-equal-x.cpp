class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<=n; i++) {
            int low = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if(i == n-low)
                return i;
        }
        return -1;
    }
};