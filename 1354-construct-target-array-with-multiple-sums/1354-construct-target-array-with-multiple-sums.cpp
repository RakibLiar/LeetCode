class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<long long int> pq;
        long long int a, sum = 0;
        for(int n: nums) {
            pq.push(n);
            sum += n;
        }
        while(pq.top() > 1) {
            sum -= pq.top();
            a = pq.top();
            if(sum == 0) return false;
            a %= sum;
            if(a == 0)
                a = sum;
            if(a == pq.top())
                return false;
            pq.pop();
            pq.push(a);
            sum += a;
        }
        while(!pq.empty() && pq.top() == 1) {
            pq.pop();
        }
        return pq.empty();
    }
};