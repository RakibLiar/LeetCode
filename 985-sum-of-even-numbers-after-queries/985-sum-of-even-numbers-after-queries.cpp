class Solution {
public:
    int addValue(int prev, int cur) {
        if(prev%2) {
            if(cur%2)
                return 0;
            else
                return cur;
        } else {
            if(cur%2)
                return -prev;
            else
                return -prev + cur;
        }
        return 0;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for(int a: nums) {
            if(a%2 == 0)
                sum += a;
        }
        for(vector<int> q: queries) {
            int ind = q[1], val = q[0];
            sum += addValue(nums[ind], nums[ind] + val);
            ans.push_back(sum);
            nums[ind] += val;
        }
        return ans;
    }
};