class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26, 0);
        for(char a: s) {
            vec[a-'a']++;
        }
        for(int i = 0; i<s.size(); i++) {
            auto a = s[i];
            if(vec[a-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};