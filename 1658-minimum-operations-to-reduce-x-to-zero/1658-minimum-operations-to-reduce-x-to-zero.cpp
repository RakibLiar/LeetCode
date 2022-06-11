class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> ascV, dscV;
        int sum1 = 0, sum2 = 0, ans = INT_MAX;
        ascV.push_back(0);
        dscV.push_back(0);
        for(int i=0, j=nums.size()-1; i<nums.size() && j>=0; i++, j--) {
            sum1 += nums[i];
            sum2 += nums[j];
            ascV.push_back(sum1);
            dscV.push_back(sum2);
        }
        for(int i=0; i<ascV.size(); i++) {
            int a = INT_MAX, b = INT_MAX;
            if(binary_search(ascV.begin(), ascV.end(), x-dscV[i])) {
                a = lower_bound(ascV.begin(), ascV.end(), x-dscV[i]) - ascV.begin();
                if(i+a<ascV.size())
                    ans = min(ans, i+a);
            }
            if(binary_search(dscV.begin(), dscV.end(), x-ascV[i])) {
                b = lower_bound(dscV.begin(), dscV.end(), x-ascV[i]) - dscV.begin();
                if(i+b<dscV.size())
                    ans = min(ans, i+b);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};