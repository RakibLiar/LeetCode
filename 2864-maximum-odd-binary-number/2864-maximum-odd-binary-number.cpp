class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.size() <= 1) return s;
        int onePos = 0, zeroPos = 1;
        while(onePos < s.size() && zeroPos < s.size()) {
            if(s[onePos] == '0' && s[zeroPos] == '1') {
                swap(s[onePos], s[zeroPos]);
            }
            
            if(s[onePos] == '1') {
                onePos++;
            }
            
            if(s[zeroPos] == '0') {
                zeroPos++;
            }
            if(onePos == zeroPos) zeroPos++;
        }
        int len = s.size();
        if(s[len-1] != '1') {
            for(int i=len-1; i>=0; i--) {
                if(s[i] == '1') {
                    swap(s[len-1], s[i]);
                    return s;
                }
            }
        }
        return s;
    }
};