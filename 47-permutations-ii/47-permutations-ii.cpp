class Solution {
public:
    unordered_map<long long, bool> ump;
    vector<vector<int>> result;
    int mod = 1e9 + 7, base = 37;
    void getPermutation(vector<int> nums, vector<int> v, vector<bool> visited, int pos, long long hash) {
        if(pos == nums.size()) {
            if(!ump[hash]) {
                result.push_back(v);
                ump[hash] = true;
            }
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!visited[i]) {
                auto temp = hash * base + nums[i];
                temp = temp%mod;
                visited[i] = true;
                v.push_back(nums[i]-10);
                getPermutation(nums, v, visited, pos+1, temp);
                visited[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            nums[i] += 10;
        }
        getPermutation(nums, v, visited, 0, 0 * 1ll);
        return result;
    }
};