class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0, b=pow(c, 0.5);

        while(a<=b){
            if(a*a+b*b==(long long)c)return true;
            else if(a*a+b*b>(long long)c)b--;
            else a++;
        }
        
        return false;
    }
};