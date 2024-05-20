class Solution {
public:
    int calculate(vector<int> &nums, int n) {
        int x = 0;
        for(int i=0; n != 0; i++, n/=2) {
            if(n&1) {
                x ^= nums[i];
            }
        }
        return x;
    }
    
    int subsetXORSum(vector<int>& nums, int pos = 0) {
        /*if(pos == nums.size()) return 0;
        return subsetXORSum(nums, pos+1) + (nums[pos] ^ subsetXORSum(nums, pos+1));*/
        
        int n = nums.size();
        int total = (1<<n), res = 0;
        
        for(int i=0; i<total; i++) {
            res += calculate(nums, i);
        }
        return res;
    }
};