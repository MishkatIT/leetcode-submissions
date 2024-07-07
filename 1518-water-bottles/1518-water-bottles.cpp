class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       return numBottles + func(numBottles, numExchange);
    }

     int func(int n, int e) {
        int ans = 0;
        if (n >= e) {
            ans += n / e;
        } else return ans;
        return ans + func(n / e + n % e, e);
     }
};