class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        for(char c: magazine) v[c-'a']++;
        for(char c: ransomNote) v[c-'a']--;
        for(int a: v) if(a<0) return false;
        return true;
    }
};