class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        for(int i=0; i<colors.size()-1; i++) {
            if(colors[i] == colors[i+1]) {
                int ct = neededTime[i], mt = neededTime[i], j;
                for(j=i+1; j<colors.size() && colors[j] == colors[i]; j++) {
                    ct += neededTime[j];
                    mt = max(mt, neededTime[j]);
                }
                time += (ct - mt);
                i = j-1;
            }
        }
        return time;
    }
};