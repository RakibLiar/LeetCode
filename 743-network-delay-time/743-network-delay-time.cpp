class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> cost(n+1, INT_MAX);
        vector<bool> visited(n+1, false);
        vector<pair<int, int>> graph[n+1];
        queue<int> q;
        for(auto v: times) {
            graph[v[0]].push_back({v[1], v[2]});
        }
        visited[k] = true;
        cost[k] = 0;
        q.push(k);
        while(!q.empty()) {
            int parent = q.front();
            q.pop();
            for(auto child: graph[parent]) {
                if(cost[parent] + child.second < cost[child.first]) {
                    cost[child.first] = min(cost[child.first], cost[parent] + child.second);
                    visited[child.first] = true;
                    q.push(child.first);
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(cost[i] == INT_MAX)
                return -1;
            ans = max(ans, cost[i]);
        }
        return ans;
    }
};