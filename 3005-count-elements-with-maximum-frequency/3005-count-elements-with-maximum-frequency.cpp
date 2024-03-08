class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for(int a: nums) {
            cnt[a]++;
        }
        int mx = 0, res = 0;
        for(int n: cnt) {
            if(n != 0) {
                if(n > mx) {
                    mx = n;
                    res = n;
                } else if(n == mx) {
                    res += n;
                }
            }
        }
        return res;
    }
};