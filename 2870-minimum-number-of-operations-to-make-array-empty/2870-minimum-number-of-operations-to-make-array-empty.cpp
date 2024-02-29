class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> cnt(1000005, 0);
        for(int &x: nums) {
            cnt[x]++;
        }

        int res = 0;
        for(int &a: cnt) {
            if(a == 1) return -1;
            if(a) res += (a / 3 + (a % 3 ? 1 : 0));
        }

        return res;
    }
};