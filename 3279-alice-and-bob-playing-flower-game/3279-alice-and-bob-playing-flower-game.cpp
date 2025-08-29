class Solution {
public:
    long long flowerGame(int n, int m) {
        long long a = n, b = m;
        long long res = ((a/2) * ((b+1)/2)) + (((a+1)/2) * (b/2));
        return res;
    }
};