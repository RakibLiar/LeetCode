class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int a: nums){
            if(!st.count(a)) {
                st.insert(a);
            } else {
                return true;
            }
        }
        return false;
    }
};