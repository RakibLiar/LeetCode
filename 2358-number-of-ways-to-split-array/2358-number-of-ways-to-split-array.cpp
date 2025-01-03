class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int a: nums) {
            sum += a;
        }
        long long cumsum = 0, res = 0;
        for(int i=0; i<nums.size()-1; i++) {
            cumsum += nums[i];
            if(2*cumsum >= sum) {
                res++;
            }
        }
        return res;
    }
};