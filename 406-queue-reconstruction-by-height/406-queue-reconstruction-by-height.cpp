class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> res(people.size(), vector<int>(2,0));
        int len = people.size();
        for(int i=0; i<len; i++) {
            res[i][0] = INT_MAX;
            res[i][1] = people[i][1];
        }
        for(int i=0; i<len; i++) {
            int a = 0;
            for(int j=0; j<len; j++) {
                if(a == people[i][1] && res[j][0] == INT_MAX) {
                    res[j] = people[i];
                    break;
                }
                if(people[i][0] <= res[j][0]) a++;
            }
        }
        return res;
    }
};