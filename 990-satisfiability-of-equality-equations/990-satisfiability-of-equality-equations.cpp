class Solution {
public:
    int find(vector<int> &par, int x) {
        if(par[x] == x) return x;
        return par[x] = find(par, par[x]);
    }
    
    void Union(vector<int> &par, int a, int b) {
        par[find(par, a)] = find(par, b);
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(26);
        for(int i=0; i<26; i++) {
            par[i] = i;
        }
        for(string s: equations) {
            if(s[1] == '=') {
                Union(par, s[0]-'a', s[3]-'a');
            }
        }
        for(string s: equations) {
            if(s[1] == '!') {
                if(find(par, s[0]-'a') == find(par, s[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};