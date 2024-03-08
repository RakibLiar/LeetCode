class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for(int a: nums) {
            cnt[a]++;
        }
        int mx = 1, res = 0;
        for(int n: cnt) {
            if(n > mx) {
                mx = res = n;
            } else if(n == mx) {
                res += n;
            }
        }
        return res;
    }
};