class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long cur = 4;
        for (int i = 2; i <= n; i++) {
            ans += cur;
            cur += 4;
        }
        return ans;
    }
};