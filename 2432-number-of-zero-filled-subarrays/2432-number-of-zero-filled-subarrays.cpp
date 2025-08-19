class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, cnt = 0;
        for(int a: nums) {
            if(a == 0) cnt++;
            else {
                res += ((cnt * (cnt+1))/2);
                cnt = 0;
            }
        }
        res += ((cnt * (cnt+1))/2);
        return res;
    }
};