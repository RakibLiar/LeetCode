class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int XOR = 0;
        for(int a: nums) {
            XOR ^= a;
        }
        XOR ^= k;
        int ans = 0;
        while(XOR != 0) {
            ans += (XOR & 1);
            XOR >>= 1;
        }
        return ans;
    }
};