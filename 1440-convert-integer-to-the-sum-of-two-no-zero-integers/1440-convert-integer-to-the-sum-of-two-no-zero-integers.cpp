class Solution {
public:
    bool isNonZero(int n) {
        while(n) {
            if(n%10 == 0) return false;
            n/=10;
        }
        return 10;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n; i++) {
            if(isNonZero(i) && isNonZero(n-i)) return {i, n-i};
        }
        return {0, 0};
    }
};