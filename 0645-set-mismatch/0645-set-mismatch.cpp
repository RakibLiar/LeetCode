class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int ind = i;
            while(nums[ind] != ind+1 && nums[ind] != nums[nums[ind]-1]) {
                swap(nums[ind], nums[nums[ind]-1]);
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i+1)
                return {nums[i], i+1};
        }
        return {};
    }
};