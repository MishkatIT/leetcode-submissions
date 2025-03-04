class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = 1;
        while (x * 3 <= n) x *= 3;
        while (x > 0) {
            if (x <= n) {
                n -= x;
            }
            x /= 3;
        }
        return n == 0;
    }
};