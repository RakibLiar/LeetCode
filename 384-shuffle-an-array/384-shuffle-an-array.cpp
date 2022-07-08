class Solution {
public:
    vector<int> original, recent;
    Solution(vector<int>& nums) {
        original = nums;
        recent = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        next_permutation(recent.begin(), recent.end());
        return recent;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */