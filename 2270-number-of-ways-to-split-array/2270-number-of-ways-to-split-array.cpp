class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> cumsum(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++) {
            cumsum[i] += cumsum[i-1];
        }
        long long cnt = 0, sum = cumsum[cumsum.size()-1];
        for(int i=0; i<cumsum.size()-1; i++) {
            if(cumsum[i] >= sum-cumsum[i])
                cnt++;
        }
        return cnt;
    }
};