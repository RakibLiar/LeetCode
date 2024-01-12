class Solution {
public:
    bool isVowel(char c) {
        c = toupper(c);
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    int countVoweInString(string s, int start, int end) {
        string v = "aeiouAEIOU";
        int c = 0;
        for(int i=start; i<end; i++) {
            c += (isVowel(s[i]));
        }
        return c;
    }
    
    bool halvesAreAlike(string s) {
        int len = s.size();
        return countVoweInString(s, 0, len/2) == countVoweInString(s, len/2, len);
    }
};