class Solution {
public:
    static bool comp(int a, int b) {
        return a>b;
    }
    int binary_bound(vector<int> &nums, int low, int val) {
        int high = nums.size()-1, pos = -1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid]>val) {
                pos = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return pos;
    }
    int triangleNumber(vector<int>& nums) {
        if(nums.size() <= 2) return 0;
        sort(nums.begin(), nums.end(), comp);
        int ans = 0, len = nums.size();
        for(int i=0; i<nums.size()-2; i++) {
            for(int j=i+1; j<nums.size()-1; j++) {
                int a = nums[i]-nums[j];
                auto lower = binary_bound(nums, j+1, a);
                if(lower != -1)
                ans += (lower-j);
            }
        }
        return ans;
    }
};