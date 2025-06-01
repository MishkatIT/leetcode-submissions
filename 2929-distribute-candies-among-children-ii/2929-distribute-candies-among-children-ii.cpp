class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int a = max(0, n - 2 * limit);
        int b = min(n, limit);
        long long ans = 0;
        while (a <= b) {
            int rem = n - a;
            int mn = max(0, rem - limit);
            int mx = min(rem, limit);
            ans += mx - mn + 1;
            ++a;
        }
        return ans;
    }
};