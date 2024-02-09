class Solution {
public:
    void findLength(vector<vector<int>> &graph, vector<int> &level, int currentNode, vector<int> &path, vector<int> &longestPath, int d) {
        if(d <= level[currentNode]) return;
        level[currentNode] = d;
        path.push_back(currentNode);
        if(path.size() > longestPath.size()) {
            longestPath = path;
        }
        for(int child: graph[currentNode]) {
            findLength(graph, level, child, path, longestPath, d + 1);
        }
        path.pop_back();
        return;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<int>> graph(nums.size());
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j]%nums[i] == 0) {
                    graph[i].push_back(j);
                }
            }
        }
        vector<int> level(nums.size(), 0);
        vector<int> path, longestPath, res;
        for(int i=0; i<nums.size(); i++) {
            if(level[i] == 0) {
                findLength(graph, level, i, path, longestPath, 1);
            }
        }
        for(int &i: longestPath) {
            res.push_back(nums[i]);
        }
        return res;
    }
};