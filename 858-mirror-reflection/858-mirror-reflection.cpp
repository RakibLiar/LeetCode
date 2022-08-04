class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = __gcd(p,q);
        if((p/g)%2 == 0) return 2;
        return (q/g)%2;
    }
};