class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> oneloss, zeroloss;
        map<int, int> mp;
        
        for(auto v: matches) {
            if(!mp.count(v[0])) mp[v[0]] = 0;
            mp[v[1]]++;
        }
        
        for(auto it: mp) {
            if(it.second == 0) zeroloss.push_back(it.first);
            if(it.second == 1) oneloss.push_back(it.first);
        }
        
        return {zeroloss, oneloss};
    }
};