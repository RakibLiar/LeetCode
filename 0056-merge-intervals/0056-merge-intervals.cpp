class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];
        for(vector<int> &v: intervals) {
            if(v[0] > end) {
                result.push_back({start, end});
                start = v[0];
                end = v[1];
            } else if(v[1] > end) end = v[1];
        }
        result.push_back({start, end});
        return result;
    }
};