class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.begin(), hap.end(), greater<int>());
        long long ans = 0;
        for(int i=0; i<k && i <= hap[i]; i++) {
            ans += (hap[i] - i);
        }
        return ans;
    }
};