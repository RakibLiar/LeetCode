class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n * (n + 1))/2;
        int sqrtx = (double)sqrt(sum) + 0.1;
        if(sqrtx * sqrtx == sum) {
            return sqrtx;
        }
        return -1;
    }
};