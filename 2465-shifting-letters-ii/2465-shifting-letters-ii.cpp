class Solution {
public:
    char getChar(char c, int n) {
        int a = (26 + n%26)%26;
        return 'a' + (c - 'a' + a)%26;
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> result(s.size()+1, 0);
        for(auto shift: shifts) {
            if(shift[2] == 1) {
                result[shift[0]]++;
                result[shift[1]+1]--;
            } else {
                result[shift[0]]--;
                result[shift[1]+1]++;
            }
        }
        int cumsum = 0;
        for(int i=0; i<result.size(); i++) {
            cumsum += result[i];
            s[i] = getChar(s[i], cumsum);
        }
        return s;
    }
};