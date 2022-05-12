class Solution {
public:
    set<vector<int>> st;
    void getPermutation(vector<int> nums, vector<int> v, vector<bool> visited, int pos) {
        if(pos == nums.size()) {
            st.insert(v);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                v.push_back(nums[i]);
                getPermutation(nums, v, visited, pos+1);
                visited[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> v;
        getPermutation(nums, v, visited, 0);
        vector<vector<int>> result;
        for(auto it: st) {
            result.push_back(it);
        }
        return result;
    }
};