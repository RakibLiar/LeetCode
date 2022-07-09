class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()==true) return 0;
        int a=10000000,i,j,n=nums.size();
        vector<int>cum_sum;
        cum_sum.push_back(nums[0]);
        for(i=1;i<n;i++)
            cum_sum.push_back(cum_sum[i-1]+nums[i]);
        
        for(i=0;i<n;i++)
        {
            int res=20000000,low=i,high=n-1,mid;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(cum_sum[mid]-cum_sum[i]+nums[i]>=s)
                {
                    res=mid-i+1;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            a=min(res,a);
        }
        if(a==10000000)
            return 0;
        return a;
        
    }
};