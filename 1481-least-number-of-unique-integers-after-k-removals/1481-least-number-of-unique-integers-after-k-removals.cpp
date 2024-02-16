class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int a: arr) {
            mp[a]++;
        }
        vector<pair<int, int>> p;
        for(auto it: mp) {
            p.push_back({it.second, it.first});
        }
        sort(p.begin(), p.end());
        for(int i=0; i<p.size() && k != 0; i++) {
            int a = p[i].first;
            p[i].first -= min(p[i].first, k);
            k -= min(a, k);
        }
        int cnt = 0;
        for(int i=0; i<p.size(); i++) {
            if(p[i].first != 0)
                cnt++;
        }
        return cnt;
    }
};