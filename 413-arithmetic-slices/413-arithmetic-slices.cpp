class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int ans = 0, cnt = 2, diff = nums[0]-nums[1];
        for(int i=2; i<nums.size();i++) {
            if(diff != nums[i-1] - nums[i]) {
                ans += ((cnt-2)*(cnt-1))/2;
                cnt = 2;
                diff = nums[i-1] - nums[i];
            } else {
                cnt++;
            }
        }
        if(cnt > 2)
            ans += ((cnt-2)*(cnt-1))/2;
        return ans;
    }
};