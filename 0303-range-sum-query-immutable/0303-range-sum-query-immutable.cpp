class NumArray {
public:
    vector<int> cumsum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int a: nums) {
            sum += a;
            cumsum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return cumsum[right];
        return cumsum[right] - cumsum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */