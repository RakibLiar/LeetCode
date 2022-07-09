class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0], 0});
        int a = nums[0];
        for(int i=1; i<nums.size(); i++) {
            while(!pq.empty() && (i-pq.top().second > k)) {
                pq.pop();
            }
            auto t = pq.top();
            pq.push({t.first+nums[i], i});
            a = t.first+nums[i];
        }
        return a;
    }
};