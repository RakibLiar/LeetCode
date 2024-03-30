class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int start = 0, end = 0, cnt = 0;
        while(end < nums.size()) {
            mp[nums[end]]++;
            while(mp.size() > k) {
                if(mp[nums[start]] == 1) {
                    mp.erase(mp.find(nums[start]));
                } else {
                    mp[nums[start]]--;
                }
                start++;
            }
            cnt += (end-start+1);
            end++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return maxSubarrayLength(nums, k) - maxSubarrayLength(nums, k-1);
    }
};