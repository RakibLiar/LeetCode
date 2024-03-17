class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& vals, vector<int>& newVal) {
        vector<vector<int>> result;
        if(vals.size() == 0) {
            result.push_back(newVal);
            return result;
        }
        int i;
        for(i = 0; i<vals.size(); i++) {
            if(newVal[1] < vals[i][0]) {
                result.push_back(newVal);
                break;
            }
            if(newVal[0] > vals[i][1]) {
                result.push_back(vals[i]);
            } else {
                vector<int> res;
                res.push_back(min(vals[i][0], newVal[0]));
                i++;
                while(i < vals.size() && newVal[1] >= vals[i][0]) {
                    i++;
                }
                res.push_back(max(vals[i-1][1], newVal[1]));
                result.push_back(res);
                break;
            }
        }
        if(i == vals.size() && newVal[0] > vals[i-1][1]) {
            result.push_back(newVal);
        }
        while(i<vals.size()) {
            result.push_back(vals[i]);
            i++;
        }
        return result;
    }
};