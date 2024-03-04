class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power) return 0;
        int score = 0, ans = 0;
        for(int i=0, j=tokens.size()-1; i<=j; ) {
            if(power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
            } else if(score > 0) {
                score--;
                power += tokens[j];
                j--;
            } else {
                break;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};