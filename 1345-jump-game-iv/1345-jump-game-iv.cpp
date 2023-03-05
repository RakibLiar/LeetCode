class Solution {
public:
    map<int, set<int> > mp;
    int resultDfs(vector<int> &arr) {
        queue<pair<int,int>>q;
        q.push({0,0});
        bool visited[arr.size() + 5];
        memset(visited, false, sizeof(visited));
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.first == arr.size()-1)
                return p.second;
            visited[p.first] = true;
            if(p.first > 0) {
                if(visited[p.first-1] == false) {
                    visited[p.first-1] = true;
                    q.push({p.first-1, p.second+1});
                }
            }
            if(p.first < arr.size()-1) {
                if(visited[p.first+1] == false) {
                    visited[p.first+1] = true;
                    q.push({p.first+1, p.second+1});
                }
            }
            auto s = mp.find(arr[p.first]);
            if(s == mp.end()) continue;
            for(auto a: mp[arr[p.first]]) {
                if(visited[a] == false) {
                    visited[a] = true;
                    q.push({a, p.second+1});
                }
                mp[arr[p.first]].erase(mp[arr[p.first]].find(a));
            }
        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].insert(i);
        return resultDfs(arr);
    }
};