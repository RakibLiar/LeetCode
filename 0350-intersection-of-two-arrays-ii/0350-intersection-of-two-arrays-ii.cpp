class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> ump;
        for(int a: nums1) {
            ump[a].first++;
        }
        for(int a: nums2) {
            ump[a].second++;
        }

        vector<int> res;
        for(auto it: ump) {
            int a = min(it.second.first, it.second.second);
            while(a--) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};