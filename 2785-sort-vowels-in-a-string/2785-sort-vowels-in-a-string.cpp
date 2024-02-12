class Solution {
public:
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    char getVowel(int a) {
        switch(a) {
            case 0:
                return 'A';
            case 1:
                return 'E';
            case 2:
                return 'I';
            case 3:
                return 'O';
            case 4:
                return 'U';
            case 5:
                return 'a';
            case 6:
                return 'e';
            case 7:
                return 'i';
            case 8:
                return 'o';
            case 9:
                return 'u';
        }
        return 0;
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
        switch(c) {
            case 'A':
                return 0;
            case 'E':
                return 1;
            case 'I':
                return 2;
            case 'O':
                return 3;
            case 'U':
                return 4;
            case 'a':
                return 5;
            case 'e':
                return 6;
            case 'i':
                return 7;
            case 'o':
                return 8;
            case 'u':
                return 9;
        }
        return 0;
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