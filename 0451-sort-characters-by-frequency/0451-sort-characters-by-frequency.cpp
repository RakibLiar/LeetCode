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
        
        for(int i=0; charCnt[i].first>0 && i<charCnt.size(); i++) {
            for(int j=0; j<charCnt[i].first; j++) {
                ans.push_back(charCnt[i].second);
            }
        }
        
        return ans;
    }
};