class Solution {
public:
    int candy(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        nums.insert(nums.begin(), INT_MAX);
        nums.push_back(INT_MAX);
        int len = nums.size();
        vector<int> v(len, 1);
        for(int i=1; i<len-1; i++) {
            if(nums[i]<nums[i-1] && nums[i]<=nums[i+1]) {
                int a = 1;
                for(int j=i; j>0 && nums[j-1]>nums[j]; j--) {
                    v[j-1] = max(v[j-1], a+1);
                    a = v[j-1];
                }
            }
            if(nums[i]<nums[i+1] && nums[i]<=nums[i-1]) {
                int a = 1;
                for(int j=i; j<len-1 && nums[j+1]>nums[j]; j++) {
                    v[j+1] = max(v[j+1], a+1);
                    a = v[j+1];
                }
            }
        }
        int ans = 0;
        for(int i=1; i<len-1; i++)
            ans += v[i];
        return ans;
    }
};