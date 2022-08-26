class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hasBefore;
        vector<string> v;
        for(int i=0; i<=(int)s.size()-10; i++) {
            string str = s.substr(i, 10);
            if(++hasBefore[str] == 2) {
                v.push_back(str);
            }
        }
        return v;
    }
};