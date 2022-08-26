class Solution {
public:
    long long MOD = 1e13 + 7;
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<long long, int> hasBefore;
        vector<string> v;
        for(int i=0; i<=(int)s.size()-10; i++) {
            long long ans = 0;
            for(int j=i; j<i+10; j++) {
                ans = (26 * ans + s[j]-'A')%MOD;
            }
            string str = s.substr(i, 10);
            hasBefore[ans]++;
            if(hasBefore[ans] == 2) {
                v.push_back(str);
            }
        }
        return v;
    }
};