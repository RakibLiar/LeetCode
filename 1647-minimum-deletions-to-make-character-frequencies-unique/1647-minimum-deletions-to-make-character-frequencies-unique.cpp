class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0), temp(26, 0);
        for(char c: s) {
            v[c-'a']++;
        }
        bool flag = true;
        int cnt = 0;
        temp = v;
        while(flag) {
            flag = false;
            sort(temp.begin(), temp.end());
            v = temp;
            for(int i=1; i<26; i++) {
                if(v[i-1] > 0 && v[i-1] == v[i]) {
                    temp[i-1]--;
                    flag = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};