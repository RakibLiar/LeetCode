class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph(n), visited(n, vector<int>(k+2, INT_MAX));
        vector<vector<int>> value(n, vector<int>(n, 0));
        queue<int> q;
        int level = 0;
        q.push(src);
        for(vector<int> v: flights) {
            graph[v[0]].push_back(v[1]);
            value[v[0]][v[1]] = v[2];
        }
        for(int i=0; i<=k; i++) {
            visited[src][0] = 0;
        }
        
        while(level <= k && !q.empty()) {
            int sz = q.size();
            while(sz--) {
                int parent = q.front();
                q.pop();
                for(int child: graph[parent]) {
                    //cout<<parent<<" "<<child<<" "<<level<<endl;
                    if(visited[child][level+1] > visited[parent][level] + value[parent][child]) {
                        visited[child][level+1] = visited[parent][level] + value[parent][child];
                        q.push(child);
                    }
                }
            }
            level++;
        }
        int res = INT_MAX;
        for(int i=0; i<=level; i++) {
            res = min(res, visited[dst][i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};