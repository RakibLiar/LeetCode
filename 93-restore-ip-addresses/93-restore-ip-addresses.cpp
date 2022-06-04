class Solution {
public:
    vector<string> result;
    bool isValid(string s) {
        if(s == "0") return true;
        if(s[0] == '0' || s.size() > 3) return false;
        if(s.size() < 3) return true;
        return s.compare("255") <= 0;
    }
    
    void getResult(int pos, string s, vector<string> &vs) {
        if(vs.size() == 4 && pos == s.size()) {
            string res = vs[0];
            for(int i=1; i<4; i++) {
                res += ('.' + vs[i]);
            }
            result.push_back(res);
            return;
        }
        if(pos >= s.size() || vs.size() >= 4)
            return;
        string str;
        for(int i=pos; i<s.size(); i++) {
            str += s[i];
            if(isValid(str)) {
                vs.push_back(str);
                getResult(i+1, s, vs);
                vs.pop_back();
            } else {
                break;
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return result;
        vector<string> str;
        getResult(0, s, str);
        return result;
    }
};