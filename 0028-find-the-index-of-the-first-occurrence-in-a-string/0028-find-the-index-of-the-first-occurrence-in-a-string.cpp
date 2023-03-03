class Solution {
public:
    void piFunction(vector<int> &pi, string pattern) {
        int now = -1;
        for(int i=1; i<pattern.size(); i++) {
            while(now != -1 && pattern[now+1] != pattern[i]) {
                now = pi[now];
            }
            if(pattern[now+1] == pattern[i]) {
                pi[i] = ++now;
            } else {
                pi[i] = now = -1;
            }
        }
    }
    
    int findPattern(vector<int> &pi, string text, string pattern) {
        int now = -1;
        for(int i=0; i<text.size(); i++) {
            while(now != -1 && text[i] != pattern[now+1]) {
                now = pi[now];
            }
            if(text[i] == pattern[now+1]) {
                now++;
            } else {
                now = -1;
            }
            if(now+1 == pattern.size()) {
                return i-pattern.size()+1;
            }
        }
        return -1;
    }
    
    int strStr(string text, string pattern) {
        if(pattern.size() == 0) return -1;
        vector<int> pi(pattern.size(), -1);
        piFunction(pi, pattern);
        return findPattern(pi, text, pattern);
    }
};