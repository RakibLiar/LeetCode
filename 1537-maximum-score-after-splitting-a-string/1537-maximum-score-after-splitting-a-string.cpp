class Solution {
public:
    int maxScore(string s) {
        int tot1 = 0, cur0 = 0, cur1 = 0, ans = 0;
        for(char c: s) {
            if(c == '1') tot1++;
        }
        for(int i=0; i<s.size()-1; i++) {
            if(s[i] == '0') cur0++;
            else cur1++;
            ans = max(ans, cur0 + tot1 - cur1);
        }
        return ans;
    }
};