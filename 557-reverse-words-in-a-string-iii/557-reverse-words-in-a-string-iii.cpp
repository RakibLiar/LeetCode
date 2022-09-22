class Solution {
public:
    string reverseWords(string s) {
        string res, temp;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                reverse(temp.begin(), temp.end());
                res = res + temp + " ";
                temp = "";
            } else {
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(), temp.end());
        res = res + temp;
        return res;
    }
};