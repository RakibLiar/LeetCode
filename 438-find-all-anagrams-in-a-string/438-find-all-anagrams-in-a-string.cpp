class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> sv(26, 0), pv(26, 0), answer;
        for(int i=0; i<p.size(); i++) {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        if(sv == pv) answer.push_back(0);
        for(int i=p.size(); i<s.size(); i++) {
            sv[s[i-p.size()]-'a']--;
            sv[s[i]-'a']++;
            if(sv == pv) answer.push_back(i-p.size()+1);
        }
        return answer;
    }
};