class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int> cnt(nums.size(), 0);
        long long ans = 0, c = 0, mx = *max_element(nums.begin(), nums.end());
        cnt[0] = (nums[0] == mx);
        c = (nums[0] == mx);
        if(nums[0] == mx && k == 1)
            ans = 1;
        for(int i=1; i<nums.size(); i++) {
            int a = nums[i];
            if(a == mx) {
                c++;
                cnt[i] = c;
            } else {
                cnt[i] = cnt[i-1];
            }
            
            if(c >= k) {
                int ind = lower_bound(cnt.begin(), cnt.begin() + i, c-k+1) - cnt.begin();
                //cout<<ind<<" "<<i<<" "<<c<<" "<<k<<endl;
                ans += (ind+1);
            }
        }
        //for(int a: cnt) cout<<a<<" ";
        return ans;
    }
};