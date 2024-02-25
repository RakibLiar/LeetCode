class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int parent) {
        for(int child: graph[parent]) {
            if(visited[child] == false) {
                visited[child] = true;
                dfs(graph, visited, child);
            }
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<vector<int>> graph(100001), anotherGraph(nums.size());
        for(int j=0; j<nums.size(); j++) {
            int n = nums[j];
            if(n == 1) return false;
            if(n % 2 == 0) {
                graph[2].push_back(j);
                while(n%2 == 0) n /= 2;
            }
            for(int i=3; i*i<=n; i+=2) {
                if(n % i == 0) {
                    graph[i].push_back(j);
                    while(n % i == 0) n /= i;
                }
            }
            if(n > 1) graph[n].push_back(j);
        }
        for(vector<int> g: graph) {
            if(g.size() > 1) {
                for(int i=1; i<g.size(); i++) {
                    anotherGraph[g[i-1]].push_back(g[i]);
                    anotherGraph[g[i]].push_back(g[i-1]);
                }
            }
        }
        vector<bool> visited(nums.size(), false);
        visited[0] = true;
        dfs(anotherGraph, visited, 0);
        for(bool b: visited) {
            if(!b) return false;
        }
        return true;
    }
};