class Solution {
public:
    int calauclateAlphabet(string s) {
        int a = 0;
        for(auto c: s) {
            int b = c-'a';
            a |= (1<<b);
        }
        return a;
    }
    int countSetBits(int n) {
        int cnt = 0;
        while(n) {
            cnt += (n&1);
            n >>= 1;
        }
        return cnt;
    }
    int maxProduct(vector<string>& words) {
        vector<int> v(words.size());
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            v[i] = calauclateAlphabet(words[i]);
        }
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if(!(v[i] & v[j])) {
                    if(words[i].size() * words[j].size() > ans) {
                        ans = words[i].size() * words[j].size();
                    }
                }
            }
        }
        return ans;
    }
};