class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] > b[1];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        int mod=1000000007;
        vector<vector<int>>vp;
        for(int i = 0;i<n;i++) {
            vp.push_back({eff[i],speed[i]});
        }
        sort(vp.begin(),vp.end(), comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long ans = 0,sum = 0;
        for(auto v:vp)
        {
            sum+=v[1];
            pq.push(v[1]);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,(sum*v[0]));
        }
        
        return ans%mod;
    }
};