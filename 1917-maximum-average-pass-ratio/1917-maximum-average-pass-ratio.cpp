class Solution {
public:
    double calculateGain(int a, int b) {
        return (double) (a+1) / (b+1) - (double) a / b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq;
        for(auto v: classes) {
            pq.push({calculateGain(v[0], v[1]), (double)v[0], (double)v[1]});
        }
        cout<<endl;
        while(!pq.empty() && extraStudents) {
            vector<double> p = pq.top();
            pq.pop();

            pq.push({calculateGain(p[1]+1, p[2]+1), p[1] + 1, p[2] + 1});
            extraStudents--;
        }
        double res = 0;
        while(!pq.empty()) {
            vector<double> v = pq.top();
            pq.pop();
            res += (v[1]/v[2]);
        }
        return res / classes.size();
    }
};