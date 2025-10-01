class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        for (int i = 1; i <= numBottles; i++) {
            ans++;
            if (i % numExchange == 0) numBottles++;
        }
        return ans;
    }
};