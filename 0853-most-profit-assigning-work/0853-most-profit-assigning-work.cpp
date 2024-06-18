class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vp;
        for(int i=0; i<difficulty.size(); i++) {
            vp.push_back({difficulty[i], profit[i]});
        }
        sort(vp.begin(), vp.end());
        sort(worker.begin(), worker.end());
        priority_queue<int> pq;
        int pos=0, res = 0;
        for(int w: worker) {
            while(pos < vp.size() && w >= vp[pos].first) {
                pq.push(vp[pos].second);
                pos++;
            }
            if(pq.empty()) continue;
            res += pq.top();
        }
        return res;
    }
};