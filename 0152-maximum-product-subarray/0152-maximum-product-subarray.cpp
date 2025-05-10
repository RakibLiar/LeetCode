class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, mul = 1;
        for(int a: nums) {
            mul *= a;
            res = max(res, mul);
            if(mul == 0) {
                mul = 1;
            }
        }
        mul = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            mul *= nums[i];
            res = max(res, mul);
            if(mul == 0) {
                mul = 1;
            }
        }
        return res;
    }
};