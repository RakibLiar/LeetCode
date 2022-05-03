class Solution {
public:
    bool isAssending(vector<int> nums) {
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        if(isAssending(nums)) {
            return 0;
        }
        int start = 0, end = nums.size()-1, ts = 0, te = nums.size()-1, mx = INT_MIN, mn = INT_MAX;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                start = i;
                break;
            }
        }
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i] < nums[i-1]) {
                end = i;
                break;
            }
        }
        cout<<start<<" "<<end<<endl;
        ts = start;
        te = end;
        for(int i=start; i<=end; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        for(int i=0; i<=start; i++) {
            if(nums[i] > mn) {
                ts = i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=end; i--) {
            if(nums[i] < mx) {
                te = i;
                break;
            }
        }
        cout<<start<<" "<<end;
        return te-ts+1;
    }
};