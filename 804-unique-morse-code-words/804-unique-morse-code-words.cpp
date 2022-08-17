class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, bool> mp;
        for(string word: words) {
            string s="";
            for(char c: word) {
                s += v[c-'a'];
            }
            mp[s] = true;
        }
        return mp.size();
    }
};