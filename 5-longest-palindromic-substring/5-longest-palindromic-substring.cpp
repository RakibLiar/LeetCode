class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,k,ans=0,res,len=s.size(),left=0,right=0;
        string result;
        for(k=0;k<len;k++)
        {
            res=1;
            for(i=k-1,j=k+1;i>=0 && j<len;i--,j++)
            {
                if(s[i]!=s[j])
                    break;
                res+=2;
            }
            if(res>ans)
            {
                left=i+1;
                right=j-1;
                ans=res;
            }
            res=0;
            for(i=k,j=k+1;i>=0 && j<len;i--,j++)
            {
                if(s[i]!=s[j])
                    break;
                res+=2;
            }
            if(res>ans)
            {
                left=i+1;
                right=j-1;
                ans=res;
            }
        }
        for(i=left;i<=right;i++)
            result.push_back(s[i]);
        return result;
    }
};