class Solution {
public:
    void versionConversion(string s, vector<int> &v) {
        long long int a = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '.') {
                v.push_back((int)a);
                a = 0;
            } else {
                a = a*10 + s[i]-'0';
            }
        }
        v.push_back((int)a);
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        versionConversion(version1, v1);
        versionConversion(version2, v2);
        int len = v1.size() > v2.size() ? v1.size()-v2.size() : v2.size() - v1.size();
        if(v1.size() > v2.size()) {
            for(int i=1; i<=len; i++)
                v2.push_back(0);
        } else {
            for(int i=1; i<=len; i++)
                v1.push_back(0);
        }
        for(int i=0; i<v1.size(); i++) {
            if(v1[i] > v2[i])
                return 1;
            if(v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};