int dp[(int)1e5];
class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        if(dp[n]) return dp[n];
        return dp[n] = fib(n - 1) + fib(n - 2);    
    }
};