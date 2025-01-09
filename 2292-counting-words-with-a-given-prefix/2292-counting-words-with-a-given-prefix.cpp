class Solution {
public:
    bool isValid(string word, string prefix) {
        if(prefix.size() > word.size()) return false;
        for(int i=0; i<prefix.size(); i++) {
            if(word[i] != prefix[i]) return false;
        }
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(string word: words) {
            res += isValid(word, pref);
        }
        return res;
    }
};