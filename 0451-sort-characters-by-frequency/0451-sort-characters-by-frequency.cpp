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
        
        for(pair<int, char> &p: charCnt) {
            if(p.first == 0) break;
            for(int i=1; i<=p.first; i++) {
                ans.push_back(p.second);
            }
        }
        
        
        
        return ans;
    }
};