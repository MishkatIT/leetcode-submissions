class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        const int inf = 1e9;
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, inf));
        dp[0][0] = triangle[0][0];
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] +  triangle[i + 1][j]);
                if (j + 1 < n) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] +  triangle[i + 1][j + 1]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};