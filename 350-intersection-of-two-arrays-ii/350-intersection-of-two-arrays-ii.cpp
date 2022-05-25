class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(1001, 0), result;
        for(int a: nums1) {
            v[a]++;
        }
        for(int a: nums2) {
            if(v[a]) {
                result.push_back(a);
                v[a]--;
            }
        }
        return result;
    }
};