class Solution {
public:
    string frequencySort(string s) {
        
        vector < char > v;
        vector < pair < int , char >> charCnt(256);
        
        for(char &c: s) {
            charCnt[c].first++;
            charCnt[c].second = c;
        }
        
        sort(charCnt.rbegin(), charCnt.rend());
        string ans = "";
        
        
        for(int i=0;i<charCnt.size() && charCnt[i].first>0;i++) {
            for(int j=0;j<charCnt[i].first;j++) {
                ans.push_back(charCnt[i].second);
            }
        }
        
        return ans;
    }
};