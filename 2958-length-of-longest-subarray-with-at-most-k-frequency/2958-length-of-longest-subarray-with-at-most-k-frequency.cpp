class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0, slow = 0;
        for(int fast = 0; fast < nums.size(); fast++) {
            mp[nums[fast]]++;
            while(mp[nums[fast]] > k) {
                res = max(res, fast - slow);
                mp[nums[slow++]]--;
            }
        }
        return max(res, (int)nums.size() - slow);
    }
};