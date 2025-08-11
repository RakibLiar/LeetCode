class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers, answer;
        for(int a = 1; n != 0; a *= 2, n/=2) {
            if(n%2 == 1) powers.push_back(a);
        }
        for(vector<int> q: queries) {
            long long a = 1;
            for(int i = q[0]; i<=q[1]; i++) {
                a *= powers[i];
                a %= 1000000007;
            }
            answer.push_back(a);
        }
        return answer;
    }
};