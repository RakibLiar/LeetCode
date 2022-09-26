class Solution {
public:
    //vector<vector<int>> par1, par2;
    vector<bool> vis1, vis2;
    vector<int> par1, par2;
    int find(vector<int> &par, int x) {
        if(par[x] == x) return x;
        return par[x] = find(par, par[x]);
    }
    
    void Union(vector<int> &par, int a, int b) {
        par[find(par, a)] = find(par, b);
    }
    
    bool isValid(string s) {
        int a = s[0] - 'a', b = s[3] - 'a';
        if(a == b) {
            if(s[1] == '=') return true;
            return false;
        }
        int pa1 = find(par1, a), pb1 = find(par1, b);
        int pa2 = find(par2, a), pb2 = find(par2, b);
        if(s[1] == '=') {
            if(pa2 == pb2)
                return false;
            Union(par1, a, b);
        } else {
            if(pa1 == pb1)
                return false;
            Union(par2, a, b);
        }
        return true;
    }
    
    /*bool dfs(vector<vector<int>> &par, vector<bool> &vis, int src, int tar) {
        if(src == tar) return true;
        if(par[src].size() == 0 || vis[src]) return false;
        vis[src] = true;
        bool a = false;
        for(int n: par[src]) {
            a |= dfs(par, vis, n, tar);
            if(a) break;
        }
        return a;
    }
    
    bool isValid(string s) {
        int a = s[0] - 'a', b = s[3] - 'a';
        if(a == b) {
            if(s[1] == '=') return true;
            return false;
        }
        vis1 = vector<bool>(26, false);
        vis2 = vector<bool>(26, false);
        bool eq1 = dfs(par1, vis1, a, b), eq2 = dfs(par2, vis2, a, b);
        if(eq1) {
            if(s[1] == '!') return false;
            return true;
        }
        if(eq2) {
            if(s[1] == '=') return false;
            return true;
        }
        if(s[1] == '=') {
            par1[a].push_back(b);
            par1[b].push_back(a);
        } else {
            par2[a].push_back(b);
            par2[b].push_back(a);
        }
        return true;
    }*/
    
    bool equationsPossible(vector<string>& equations) {
        par1 = vector<int>(26);
        par2 = vector<int>(26);
        for(int i=0; i<26; i++) {
            par1[i] = par2[i] = i;
        }
        for(string s: equations) {
            if(s[1] == '=') {
                Union(par1, s[0]-'a', s[3]-'a');
            }
        }
        for(string s: equations) {
            if(s[1] == '!') {
                if(find(par1, s[0]-'a') == find(par1, s[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};