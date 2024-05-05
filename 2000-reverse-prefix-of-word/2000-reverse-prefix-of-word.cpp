class Solution {
public:
    string reversePrefix(string word, char ch) {
        int firstOccurance = -1;
        for(int i=0; i<word.size(); i++) {
            if(word[i] == ch) {
                firstOccurance = i;
                break;
            }
        }
        if(firstOccurance == -1) return word;
        string res = "";
        for(int i=firstOccurance; i>=0; i--) {
            res.push_back(word[i]);
        }
        for(int i=firstOccurance+1; i<word.size(); i++) {
            res.push_back(word[i]);
        }
        return res;
    }
};