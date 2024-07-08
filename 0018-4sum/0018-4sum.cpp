class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); j++) {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int first = j+1, last = nums.size()-1;
                while(first < last) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[first] + (long long)nums[last];
                    //cout<<i<<" "<<j<<" "<<first<<" "<<last<<endl;
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[first], nums[last]});
                        while(first < last && nums[first] == nums[first+1]) 
                            first++;
                        while(first < last && nums[last] == nums[last-1]) 
                            last--;
                        first++;
                        last--;
                    } else if(sum > target) {
                        last--;
                    } else {
                        first++;
                    }
                }
            }
        }
        return result;
    }
};