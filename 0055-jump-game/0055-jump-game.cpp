class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int cur=0, next = 0;
        for(int i=0; i<nums.size()-1; i++) {
            next = max(next, i+nums[i]);
            if(cur == i) {
                cur = next;
                if(cur >= nums.size()-1) return true;
                if(cur == i && nums[i] == 0) return false;
            }
        }
        return false;
    }
};