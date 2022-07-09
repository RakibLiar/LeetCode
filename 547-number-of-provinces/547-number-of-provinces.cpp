class Solution {
public:
    void dfs(int src, vector<bool> &visited, vector<vector<int>> &graph) {
        visited[src] = true;
        for(auto child: graph[src]) {
            if(!visited[child]) {
                dfs(child, visited, graph);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int g: graph[i]) {
                if(!visited[g]) {
                    dfs(g, visited, graph);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};