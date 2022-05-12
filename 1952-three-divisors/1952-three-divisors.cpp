class Solution {
public:
    bool isPrime(int n) {
        if(n == 1) return false;
        for(int i = 2; i*i<=n; i++) {
            if(n%i == 0)
                return false;
        }
        return true;
    }
    bool isThree(int n) {
        int a = round(sqrt(n));
        if(a*a == n) {
            if(isPrime(a))
                return true;
        }
        return false;
    }
};