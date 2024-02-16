class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int a: arr) {
            mp[a]++;
        }
        vector<int> v;
        for(auto it: mp) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<v.size(); i++) {
            if(k - v[i] >= 0) {
                int a = v[i];
                v[i] -= k;
                ans++;
                k -= a;
            }
        }
        return v.size() - ans;
    }
};