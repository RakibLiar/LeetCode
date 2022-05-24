class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a!=0 || b!=0 || c!=0) {
            bool b1 = a&1, b2 = b&1, b3 = c&1;
            if((b1 | b2) != b3) {
                if(b3) {
                    cnt++;
                } else {
                    if(b1 == b2) {
                        cnt += 2;
                    } else {
                        cnt++;
                    }
                }
            }
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return cnt;
    }
};