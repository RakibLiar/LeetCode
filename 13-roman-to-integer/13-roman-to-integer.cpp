class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'I') {
                ans += 1;
            } else if(s[i] == 'V') {
                if(i>0 && s[i-1] == 'I') {
                    ans += 3;
                } else {
                    ans += 5;
                }
            } else if(s[i] == 'X') {
                if(i>0 && s[i-1] == 'I') {
                    ans += 8;
                } else {
                    ans += 10;
                }
            } else if(s[i] == 'L') {
                if(i>0 && s[i-1] == 'X') {
                    ans += 30;
                } else {
                    ans += 50;
                }
            } else if(s[i] == 'C') {
                if(i>0 && s[i-1] == 'X') {
                    ans += 80;
                } else {
                    ans += 100;
                }
            } else if(s[i] == 'D') {
                if(i>0 && s[i-1] == 'C') {
                    ans += 300;
                } else {
                    ans += 500;
                }
            } else {
                if(i>0 && s[i-1] == 'C') {
                    ans += 800;
                } else {
                    ans += 1000;
                }
            }
        }
        return ans;
    }
};