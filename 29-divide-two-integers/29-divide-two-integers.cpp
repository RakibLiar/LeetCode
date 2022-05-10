class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a,b,c,ans=0,d,s=1;
        long long div, dis;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            s=-1;
        }
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor==1 || divisor==-1)
            return dividend*divisor;
        div=labs(dividend);
        dis=labs(divisor);
        
        while(div>=dis)
        {
            a=0;
            b=dis;
            c=1;
            while(div>=b)
            {
                a=c;
                c=c<<1;
                d=b;
                b=b<<1;
            }
            ans+=a;
            div=div-d;
        }
        long long res = ans*s;
        if(res == INT_MIN)
            return INT_MAX;
        return res;
    }
};