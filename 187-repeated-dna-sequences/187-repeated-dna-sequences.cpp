class Solution {
public:
    long long MOD = 1e13 + 7;
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> hasTaken;
        unordered_map<long long, bool> hasBefore;
        vector<string> v;
        for(int i=0; i<=(int)s.size()-10; i++) {
            long long ans = 0;
            for(int j=i; j<i+10; j++) {
                ans = (26 * ans + s[j]-'A')%MOD;
            }
            string str = s.substr(i, 10);
            if(!hasTaken[str] && hasBefore[ans]) {
                hasTaken[str] = true;
                v.push_back(str);
            }
            hasBefore[ans] = true;
        }
        return v;
    }
};