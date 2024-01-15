class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> player(100001, 0), oneloss, zeroloss;
        vector<bool> vis(100001, false);
        for(vector<int> v: matches) {
            player[v[1]]++;
            vis[v[0]] = vis[v[1]] = true;
        }
        for(int i=1; i<=100000; i++) {
            if(vis[i]) {
                if(player[i] == 0) {
                    zeroloss.push_back(i);
                } else if(player[i] == 1) {
                    oneloss.push_back(i);
                }
            }
        }
        return {zeroloss, oneloss};
    }
};