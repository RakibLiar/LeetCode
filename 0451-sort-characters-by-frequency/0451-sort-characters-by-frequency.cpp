class Solution {
public:
    string frequencySort(string s) {
        vector < pair < int , char >> charCnt(62);
        
        for(char &c: s) {
            if(c >= 'a' && c <= 'z') {
                charCnt[c-'a'].first++;
                charCnt[c-'a'].second = c;
            } else if(c >= 'A' && c <= 'Z') {
                charCnt[c-'A' + 26].first++;
                charCnt[c-'A' + 26].second = c;
            } else {
                charCnt[c-'0' + 52].first++;
                charCnt[c-'0' + 52].second = c;
            }
        }
        
        sort(charCnt.begin(), charCnt.end(), [&](pair<int, char> &a, pair<int, char> &b) {
            return a.first > b.first;
        });
        
        string ans = "";
        int a = -1;
        
        while(a < 61 && charCnt[++a].first != 0) {
            for(int i=0; i<charCnt[a].first; i++) {
                ans.push_back(charCnt[a].second);
            }
        }
        
        return ans;
    }
};