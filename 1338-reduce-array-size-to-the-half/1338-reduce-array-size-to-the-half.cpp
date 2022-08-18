class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v(100001, 0);
        priority_queue<int> pq;
        for(int a: arr) {
            v[a]++;
        }
        for(int a: v) {
            pq.push(a);
        }
        int n = arr.size(), ans = 0, cnt = 0;
        while(ans < n/2) {
            ans += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};