class Solution {
public:
    string largestOddNumber(string num) {
        string res = "", temp = "";
        for(char c: num) {
            temp += c;
            if((c-'0') % 2 == 1) res = temp;
        }
        return res;
    }
};