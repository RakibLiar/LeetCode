class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 1) return {};
        sort(nums.begin(), nums.end());
        vector<int> count(nums[n-1]+1, 0), res;
        for(int a: nums) {
            count[a]++;
        }
        for(int i=0; i<n && res.size() < n/2  && 2*nums[i] <= nums[n-1]; i++) {
            if(count[nums[i]] == 0) continue;
            if(count[2*nums[i]] <= 0) return {};
            res.push_back(nums[i]);
            count[nums[i]]--;
            count[2*nums[i]]--;
        }
        if(res.size() != n/2)
            return {};
        for(int a: count) {
            if(a != 0)
                return {};
        }
        return res;
    }
};