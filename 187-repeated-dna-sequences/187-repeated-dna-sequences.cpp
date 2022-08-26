class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<long long, int> hasBefore;
        vector<string> v;
        for(int i=0; i<=(int)s.size()-10; i++) {
            long long ans = 0;
            for(int j=i; j<i+10; j++) {
                ans = (5 * ans + (s[j]-'A'+1)%5);
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