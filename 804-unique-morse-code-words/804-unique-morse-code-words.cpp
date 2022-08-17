class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(string word: words) {
            string s="";
            for(char c: word) {
                s += v[c-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};