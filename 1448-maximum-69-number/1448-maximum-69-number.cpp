class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i, res = 0;
        for(i = 0; i<s.size(); i++) {
            res = 10 * res + 9;
            if(s[i] == '6') {
                break;
            }
        }
        i++;
        while(i < s.size()) {
            res = 10 * res + s[i] - '0';
            i++;
        }
        return res;
    }
};