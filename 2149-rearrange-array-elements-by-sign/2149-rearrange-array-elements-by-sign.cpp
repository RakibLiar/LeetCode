class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posind = 0, negind = 1;
        for(int n: nums) {
            if(n>0) {
                ans[posind] = n;
                posind += 2;
            }
            else {
                ans[negind] = n;
                negind += 2;
            }
        }
        return ans;
    }
};