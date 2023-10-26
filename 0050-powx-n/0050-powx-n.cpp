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
/*
    To implement this problem's solution, you can use binary exponentiation or the built-in 'pow' function of C++ or equivalent in other languages. 
    If power is negative then we can break it down like this:
    for example x = 5, n = -3;
    5 ^ -3 can be written as 1 / (5 ^ 3). 
    simply calculate pow (5, 3) then divide 1 by the result. 
*/
