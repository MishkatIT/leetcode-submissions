using ll = long long;
const ll inf = 1e9;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suf(n);

        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = piles[i] + suf[i + 1];
        }

        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (i == n) return 0;
            if (dp[i][m] != -1) return dp[i][m];

            int ans = 0;
            for (int x = 1; x <= 2 * m; x++) {
                if (i + x <= n) {
                    ans = max(ans, suf[i] - dfs(i + x, max(m, x)));
                }
            }

            return dp[i][m] = ans;
        };

        return dfs(0, 1);
    }
};