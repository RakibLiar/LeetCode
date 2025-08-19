class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int sum = 0, res = 0, cumsum = 0;
        for(int a: nums) sum += a;
        for(int i=0; i<nums.size()-1; i++) {
            int a = nums[i];
            cumsum += a;
            if(2 * cumsum >= sum) res++;
        }
        return res;
    }
};