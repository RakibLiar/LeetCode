class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> v(10001, -1);
        int sum = 0, ans = INT_MIN, start = 0;
        for(int i=0; i<nums.size(); i++) {
            if(v[nums[i]] != -1) {
                int s = 0;
                for(int j=start; j<=v[nums[i]]; j++)
                    s += nums[j];
                start = max(start, v[nums[i]]+1);
                sum -= s;
            }
            sum += nums[i];
            v[nums[i]] = i;
            ans = max(ans, sum);
        }
        return ans;
    }
};