class Solution {
public:
    double myPow(double x, double n) {
        bool neg = false;
        if(n < 0)
            neg = true;
        if(neg)
            n *= -1;   
        n = pow(x, n);
        if(neg)
            n  = 1 / n;
        return n;    
    }
};