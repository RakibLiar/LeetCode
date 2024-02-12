class Solution {
public:
    string greatestLetter(string s) {
        char res = '0';
        vector<bool> v(52, false);
        for(char c: s) {
            if(c >= 'A' && c <= 'Z') {
                v[c - 'A'] = true;
            } else {
                v[26 + c - 'a'] = true;
            }
            int lower = 26 + tolower(c) - 'a';
            int upper = toupper(c) - 'A';
            if(v[lower] && v[upper] && res < toupper(c)) {
                res = toupper(c);
            }
        }
        string a = "";
        return res != '0' ? (a + res) : "";
    }
};