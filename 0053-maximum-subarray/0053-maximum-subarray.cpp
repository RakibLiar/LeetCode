class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subSum = 0, res = INT_MIN;
        for(int a: nums) {
            subSum += a;
            res = max(res, subSum);
            if(subSum < 0) subSum = 0;
        }
        return res;
    }
};