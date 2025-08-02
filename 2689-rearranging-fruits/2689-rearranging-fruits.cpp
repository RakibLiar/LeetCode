class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        long long minx = INT_MAX;
        for(int i: basket1) {
            freq[i]++;
            minx = min(minx, (long long)i);
        }
        
        for(int i: basket2) {
            freq[i]--;
            minx = min(minx, (long long)i);
        }

        for(auto &[k, v]: freq) {
            if(v & 1) return -1;
        }

        vector<int> vec;

        for(auto &[k, v]: freq) {
            for(int i=0; i<abs(v)/2; i++) {
                vec.push_back(k);
            }
        }

        sort(vec.begin(), vec.end());
        long long ans = 0, g = 2LL * minx;
        for(int i=0; i<vec.size()/2; i++) {
            ans += min((long long)vec[i], g);
        }

        return ans;
    }
};