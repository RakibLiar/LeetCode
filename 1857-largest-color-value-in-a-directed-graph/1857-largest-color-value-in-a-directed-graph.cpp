class Solution {
public:
    int largestPathValue(string cs, vector<vector<int>>& edges) {
        vector<vector<int>> al(cs.size()), cnt(cs.size(), vector<int>(26));
        vector<int> indegrees(cs.size());
        for (auto &e: edges) {
            al[e[0]].push_back(e[1]);
            ++indegrees[e[1]];
        }
        queue<int> q;
        for (int i = 0; i < cs.size(); ++i) {
            if (indegrees[i] == 0)
                q.push(i);
        }
        int res = 0, processed = 0;
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            ++processed;
            res = max(res, ++cnt[parent][cs[parent] - 'a']);
            for (auto j : al[parent]) {
                for (auto k = 0; k < 26; ++k)
                    cnt[j][k] = max(cnt[j][k], cnt[parent][k]);
                if (--indegrees[j] == 0)
                    q.push(j);
            }
        }
        return processed != cs.size() ? -1 : res;
    }
};