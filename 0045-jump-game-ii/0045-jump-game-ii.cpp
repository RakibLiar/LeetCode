class Solution {
public:
    int jump(vector<int>& nums) {
        int currentMax = 0, nextMax = 0, jumps = 0;
        for(int i=0; i<nums.size()-1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if(i == currentMax) {
                currentMax = nextMax;
                jumps++;
                if(currentMax >= nums.size() - 1) return jumps;
            }
        }
        return -1;
    }
};