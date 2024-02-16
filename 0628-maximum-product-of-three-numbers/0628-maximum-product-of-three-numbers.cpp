class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3) return nums[0] * nums[1] * nums[2];
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int a: nums) {
            if(a > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = a;
            } else if(a > mx2) {
                mx3 = mx2;
                mx2 = a;
            } else if(a > mx3) {
                mx3 = a;
            }

            if(a < min1) {
                min2 = min1;
                min1 = a;
            } else if(a < min2) {
                min2 = a;
            }
        }
        return max(mx1 * mx2 * mx3, mx1 * min1 * min2);
    }
};