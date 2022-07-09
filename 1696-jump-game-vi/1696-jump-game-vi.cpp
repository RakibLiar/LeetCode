class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> dp(nums.size(), INT_MIN);
        pq.push({nums[0], 0});
        dp[0] = nums[0];
        int a = dp[0];
        for(int i=1; i<nums.size(); i++) {
            while(!pq.empty() && (i-pq.top().second > k)) {
                pq.pop();
            }
            auto t = pq.top();
            //cout<<i<<" "<<t.first<<" "<<t.second<<endl;
            pq.push({t.first+nums[i], i});
            a = t.first+nums[i];
        }
        return a;
    }
};