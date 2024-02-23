class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<int>> distance(n, vector<int>(k+2, INT_MAX));
        queue<int> q;
        int level = 0;
        q.push(src);
        for(vector<int> v: flights) {
            graph[v[0]].push_back({v[1], v[2]});
        }
        for(int i=0; i<=k; i++) {
            distance[src][0] = 0;
        }
        
        while(level <= k && !q.empty()) {
            int sz = q.size();
            while(sz--) {
                int parent = q.front();
                q.pop();
                for(pair<int, int> &childPair: graph[parent]) {
                    int child = childPair.first;
                    int value = childPair.second;
                    if(distance[child][level+1] > distance[parent][level] + value) {
                        distance[child][level+1] = distance[parent][level] + value;
                        q.push(child);
                    }
                }
            }
            level++;
        }
        int res = INT_MAX;
        for(int i=0; i<=level; i++) {
            res = min(res, distance[dst][i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};