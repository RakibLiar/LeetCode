class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        vector<vector<int>> answer;
        while(i<firstList.size() && j<secondList.size()) {
            if(firstList[i][1] < secondList[j][0])
                i++;
            else if(firstList[i][0] > secondList[j][1])
                j++;
            else{
                int a = max(firstList[i][0], secondList[j][0]);
                int b = min(firstList[i][1], secondList[j][1]);
                answer.push_back({a, b});
                if(firstList[i][1] < secondList[j][1])
                    i++;
                else
                    j++;
            }
        }
        return answer;
    }
};