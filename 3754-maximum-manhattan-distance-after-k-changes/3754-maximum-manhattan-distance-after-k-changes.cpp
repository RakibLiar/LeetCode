class Solution {
public:
    int maxDistance(string str, int k) {
        int ans = 0, e = 0, w = 0, n = 0, s = 0;

        for(int i=0; i<str.size(); i++) {
            char c = str[i];
            if(c == 'E') e++;
            else if(c == 'W') w++;
            else if(c == 'N') n++;
            else s++;

            int x = abs(e-w);
            int y = abs(n-s);
            int md = x+y;
            int dis = md + min(2*k, (i+1) - md);
            ans = max(ans, dis);
        }
        return ans;
    }
};