class Solution {
public:
    int calculate(int pos1, int pos2, int pos3, string s1, string s2, string s3, vector<vector<vector<int>>> &dp) {
        //cout<<pos1<<" "<<pos2<<" "<<pos3<<endl;
        if(pos1 + pos2 == s3.size())
            return 1;
        if(pos3 >= s3.size())
            return 0;
        if(pos1 == s1.size()) {
            for(int i=pos2, j=pos3; i<s2.size(); i++, j++) {
                if(s2[i] != s3[j])
                    return 0;
            }
            return 1;
        }
        if(pos2 == s2.size()) {
            for(int i=pos1, j=pos3; i<s1.size(); i++, j++) {
                if(s1[i] != s3[j])
                    return 0;
            }
            return 1;
        }
        if(dp[pos1][pos2][pos3] != -1) return dp[pos1][pos2][pos3];
        if(s1[pos1] != s3[pos3] && s2[pos2] != s3[pos3])
            return dp[pos1][pos2][pos3] = 0;
        if(s1[pos1] == s3[pos3])
            dp[pos1][pos2][pos3] = calculate(pos1+1, pos2, pos3+1, s1, s2, s3, dp);
        if(s2[pos2] == s3[pos3])
            dp[pos1][pos2][pos3] = max(dp[pos1][pos2][pos3], calculate(pos1, pos2+1, pos3+1, s1, s2, s3, dp));
        return dp[pos1][pos2][pos3];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<vector<int>>> dp(s1.size(), vector<vector<int>>(s2.size(), vector<int>(s3.size(), -1)));
        return calculate(0, 0, 0, s1, s2, s3, dp) == 1 ? true : false;
    }
};