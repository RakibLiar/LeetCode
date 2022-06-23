class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];  
        });
        int time = 0;
        priority_queue<int> pq;
        for(auto a: v) {
            if(time + a[0] <= a[1]) {
                time += a[0];
                pq.push(a[0]);
            } else if(!pq.empty() && pq.top() > a[0]) {
                time = time - pq.top() + a[0];
                pq.pop();
                pq.push(a[0]);
            }
        }
        return pq.size();
    }
};