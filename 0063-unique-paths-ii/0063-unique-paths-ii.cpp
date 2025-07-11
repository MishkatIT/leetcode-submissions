class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        if (obstacleGrid[0][0] == 0) dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                int up = 0, left = 0;
                if (i - 1 >= 0) {
                    if (!obstacleGrid[i][j]) up = dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    if (!obstacleGrid[i][j]) left = dp[i][j - 1];
                }
                dp[i][j] = left + up;
            }
        }
        return dp[n - 1][m - 1];
    }
};