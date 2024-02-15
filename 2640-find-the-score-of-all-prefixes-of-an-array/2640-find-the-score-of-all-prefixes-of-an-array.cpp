class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long sum = 0, mx = nums[0], cv;
        for(int a: nums) {
            mx = max((long long)a, mx);
            cv = mx + a;
            sum += cv;
            ans.push_back(sum);
        }
        return ans;
    }
};