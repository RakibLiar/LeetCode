class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans, cnt = 0;
        for(int n: nums) {
            if(n == 0)
                cnt++;
            else
                cnt = 0;
            ans += cnt;
        }
        return ans;
    }
};