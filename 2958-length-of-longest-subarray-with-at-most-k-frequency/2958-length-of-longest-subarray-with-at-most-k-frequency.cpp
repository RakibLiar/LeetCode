class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0, slow = -1;
        for(int fast = 0; fast < nums.size(); fast++) {
            mp[nums[fast]]++;
            while(mp[nums[fast]] > k) {
                mp[nums[++slow]]--;
            }
            res = max(res, fast - slow);
        }
        return res;
    }
};