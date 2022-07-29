class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN, maxValue = values[0];
        for(int i=1; i<values.size(); i++) {
            ans = max(ans, maxValue + values[i]-i);
            maxValue = max(maxValue, values[i]+i);
        }
        return ans;
    }
};