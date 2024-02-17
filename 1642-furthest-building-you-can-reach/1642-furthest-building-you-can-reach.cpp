class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i = 0; i<heights.size()-1; i++) {
            if(heights[i+1] > heights[i]) {
                int a = heights[i+1] - heights[i];
                pq.push(a);
                if(pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                if(bricks < 0) break;
            }
        }
        return i;
    }
};