class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int a = minutesToTest / minutesToDie;
        return ceil(log2(buckets) / log2((int)(a) + 1));
    }
};