class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int first = 1, last = 1;
        vector<int> firstV(nums.size()), lastV(nums.size());
        for(int i=0, j = nums.size()-1; i<nums.size()-1 && j > 0; i++, j--) {
            first *= nums[i];
            last *= nums[j];
            firstV[i] = first;
            lastV[j] = last;
        }
        vector<int> res(nums.size());
        res[0] = last;
        for(int i=1; i<nums.size()-1; i++) {
            res[i] = firstV[i-1] * lastV[i+1];
        }
        res[nums.size()-1] = first;
        return res;
    }
};