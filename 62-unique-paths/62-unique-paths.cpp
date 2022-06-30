class Solution {
public:
    double f(double n,double r){
        if(r>0)
            return (n/r)*f(n-1,r-1);
        else
            return 1;
    }
    
    int uniquePaths(int m, int n) {
        return round(f(m+n-2,n-1));
    }
};