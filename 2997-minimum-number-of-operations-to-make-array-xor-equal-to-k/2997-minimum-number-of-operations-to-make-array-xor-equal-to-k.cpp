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
            ans += (XOR % 2);
            XOR /= 2;
        }
        return ans;
    }
};