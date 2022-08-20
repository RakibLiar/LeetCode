class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int res = 0, id = 0;
        while(fuel < target) {
            while(id < stations.size() && stations[id][0] <= fuel) {
                pq.push(stations[id++][1]);
            }
            if(pq.empty()) return -1;
            fuel += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};