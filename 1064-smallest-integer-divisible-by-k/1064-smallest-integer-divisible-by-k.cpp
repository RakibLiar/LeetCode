class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0, i;
        unordered_map<int, bool> mp;
        for(i = 1; i<=k; i++) {
            num = (10 * num + 1) % k;
            if(num == 0) return i;
            if(mp.count(num)) return -1;
            mp[num] = true;
        }
        return -1;
    }
};