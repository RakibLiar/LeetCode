class Solution {
public:
    int countSubstrings(string s) {
        int i,j,k,ans=0, len = s.size();
        string result;
        for(k=0;k<len;k++)
        {
            for(i=k,j=k;i>=0 && j<len;i--,j++)
            {
                if(s[i]!=s[j])
                    break;
                ans++;
            }
            for(i=k,j=k+1;i>=0 && j<len;i--,j++)
            {
                if(s[i]!=s[j])
                    break;
                ans++;
            }
        }
        return ans;
    }
};