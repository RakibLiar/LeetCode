class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int a = 1;
        while(a <= c/a) {
            int b = c - a*a;
            int srb = sqrt(b);
            if(srb * srb == b) return true;
            a++;
        }
        return false;
    }
};