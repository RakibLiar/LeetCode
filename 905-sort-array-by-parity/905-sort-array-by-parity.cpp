class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high) {
            if(nums[low]%2 == 1 && nums[high]%2 == 0) {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
            if(nums[low]%2 == 0)
                low++;
            if(nums[high]%2)
                high--;
        }
        return nums;
    }
};