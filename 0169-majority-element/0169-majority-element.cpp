class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res = nums[0];
        for(int a: nums) {
            if(cnt == 0) {
                cnt = 1;
                res = a;
            } else if(a == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};