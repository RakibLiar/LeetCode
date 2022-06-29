class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size(),i,j,st,ed;
        vector<vector<int>>res;
        map<int,map<int,int>>mp;
        for(i=0;i<sz-2;i++){
            if(i != 0 && nums[i-1] == nums[i])
                continue;
            st=i+1;
            ed=sz-1;
            while(st<ed){
                int s = nums[st]+nums[ed];
                if(s==-nums[i]){
                    res.push_back({nums[i], nums[st], nums[ed]});
                    while(st<ed && nums[st] == nums[st+1]) st++;
                    while(st<ed && nums[ed] == nums[ed-1]) ed--;
                    st++;
                    ed--;
                }
                else if(s<-nums[i])
                    st++;
                else
                    ed--;
            }
        }
        return res;
    }
};