class Solution {
public:
    string vowelString = "AEIOUaeiou";
    
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    char getVowel(int a) {
        return vowelString[a];
    }
    
    char getVowelIndex(char c, vector<int> &v) {
        for(int i=0; i<10; i++) {
            if(v[i] != 0) {
                v[i]--;
                return getVowel(i);
            }
        }
        return 0;
    }
    
    int vowelIndex(char c) {
        return vowelString.find(c);
    }
    
    string sortVowels(string s) {
        vector<int> vowel(10, 0);
        for(char c: s) {
            if(isVowel(toupper(c))) {
                vowel[vowelIndex(c)]++;
            }
        }
        for(int i=0; i<s.size(); i++) {
            if(isVowel(toupper(s[i]))) {
                //cout<<s[i]<<" "<<getVowelIndex(s[i], vowel)<<endl;
                s[i] = getVowelIndex(s[i], vowel);
            }
        }
        return s;
    }
};