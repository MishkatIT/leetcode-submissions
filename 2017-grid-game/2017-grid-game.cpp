class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<long long> a(m), b(m);
        a[0] = grid[0][0], b[0] = grid[1][0];
        for (int i = 1; i < m; i++) a[i] = a[i - 1] + grid[0][i];
        for (int i = 1; i < m; i++) b[i] = b[i - 1] + grid[1][i];
        long long mn = 1e18;
        for (int i = 0; i < m; i++) {
            long long x = 0, y = 0;
            if (i < m - 1) {
                x = a[m - 1] - a[i];
            }
            if (i > 0) {
                y = b[i - 1];
            }
            mn = min(mn, max(x, y));
        }
        return mn;
    }
};