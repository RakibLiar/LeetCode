class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                cnt++;
                if(i == 0)
                    nums[0] = -100000;
                else if(nums[i+1] >= nums[i-1]){
                    nums[i] = nums[i-1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        return cnt <= 1;
    }
};