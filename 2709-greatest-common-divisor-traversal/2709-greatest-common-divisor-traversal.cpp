class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int parent) {
        if(visited[parent] == true) return;
        visited[parent] = true;
        for(int child: graph[parent]) {
            if(visited[child] == false) {
                dfs(graph, visited, child);
            }
        }
    }
    
    vector<vector<int>> primeFactorize(vector<int> &nums) {
        vector<vector<int>> graph(100001);
        for(int j=0; j<nums.size(); j++) {
            int n = nums[j];
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
        return graph;
    }
    
    vector<vector<int>> createGraph(vector<vector<int>> &factorizedGraph, int size) {
        vector<vector<int>> graph(size);
        for(vector<int> g: factorizedGraph) {
            if(g.size() > 1) {
                for(int i=1; i<g.size(); i++) {
                    graph[g[i-1]].push_back(g[i]);
                    graph[g[i]].push_back(g[i-1]);
                }
            }
        }
        return graph;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int n: nums) {
            if(n == 1) return false;
        }
        set<int> st(nums.begin(), nums.end());
        nums = vector<int>(st.begin(), st.end());
        vector<vector<int>> factorizedGraph = primeFactorize(nums);
        vector<vector<int>> anotherGraph = createGraph(factorizedGraph, nums.size());
        vector<bool> visited(nums.size(), false);
        dfs(anotherGraph, visited, 0);
        for(bool b: visited) {
            if(!b) return false;
        }
        return true;
    }
};