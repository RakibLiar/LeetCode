class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> v(values.size());
        for(int i=0; i<values.size(); i++) {
            v[i] = values[i]+i;
        }
        int ans = INT_MIN, maxValue = v[0];
        for(int i=1; i<values.size(); i++) {
            ans = max(ans, maxValue + values[i]-i);
            maxValue = max(maxValue, v[i]);
        }
        return ans;
    }
};