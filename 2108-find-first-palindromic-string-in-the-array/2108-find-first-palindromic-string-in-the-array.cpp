class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &word: words) {
            string s = word;
            reverse(s.begin(), s.end());
            if(s == word) return s;
        }
        return "";
    }
};