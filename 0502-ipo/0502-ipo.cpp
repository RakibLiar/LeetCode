class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> vp;
        for(int i=0; i<profits.size(); i++) {
            vp.push_back({capital[i], profits[i], 0});
        }
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        int i = 0;
        while(k > 0) {
            for(; i<vp.size() && vp[i][0] <= w; i++) {
                pq.push(vp[i][1]);
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};