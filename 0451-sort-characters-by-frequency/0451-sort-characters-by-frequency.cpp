class Solution {
public:
    string frequencySort(string s) {
        
        vector < char > v;
        vector < pair < int , char >> charCnt(256);
        
        for(char &c: s) {
            charCnt[c].first++;
            charCnt[c].second = c;
        }
        
        sort(charCnt.begin(), charCnt.end(), [&](pair<int, char> &a, pair<int, char> &b) {
            return a.first > b.first;
        });
        string ans = "";
        int a = -1;
        
        while(charCnt[++a].first != 0) {
            for(int i=0; i<charCnt[a].first; i++) {
                ans.push_back(charCnt[a].second);
            }
        }
        
        return ans;
    }
};