class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int neg = INT_MIN, pos = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i];
            if(a < 0) {
                neg = max(neg, i);
            } else {
                pos = min(pos, i);
            }
        }
        vector<int> res;
        while(neg >= 0 && pos < nums.size()) {
            if(abs(nums[neg]) > abs(nums[pos])) {
                res.push_back(nums[pos]*nums[pos]);
                pos++;
            } else {
                res.push_back(nums[neg]*nums[neg]);
                neg--;
            }
        }
        while(neg >= 0) {
            res.push_back(nums[neg]*nums[neg]);
            neg--;
        }
        while(pos < nums.size()) {
            res.push_back(nums[pos]*nums[pos]);
            pos++;
        }
        return res;
    }
};