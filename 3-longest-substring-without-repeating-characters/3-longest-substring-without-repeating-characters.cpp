class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            vector<bool> vec(256, false);
            int j = 0;
            for(j=0; j<256 && i+j<s.size(); j++) {
                if(vec[s[i+j]])
                    break;
                vec[s[i+j]] = true;
            }
            ans = max(ans, j);
        }
        return ans;
    }
};