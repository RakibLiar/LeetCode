class Solution {
public:
    int setValue(vector<char> &s, int lastPos, int curPos, int cnt) {
        string cs = to_string(cnt);
        s[lastPos++] = s[curPos];
        for(char c: cs) {
            s[lastPos++] = c;
        }
        return lastPos;
    }
    
    int compress(vector<char>& chars) {
        int cnt = 1, lastPos = 0;
        for(int i=1; i<chars.size(); i++) {
            if(chars[i] != chars[i-1]) {
                if(cnt == 1) {
                    chars[lastPos++] = chars[i-1];
                } else {
                    lastPos = setValue(chars, lastPos, i-1, cnt);
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(cnt == 1) {
            chars[lastPos++] = chars[chars.size()-1];
            return lastPos;
        }
        return setValue(chars, lastPos, chars.size()-1, cnt);
    }
};