class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, auto& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9;
        if (dp[i][j] != -1) return dp[i][j];
        int left = solve(grid, i, j - 1, dp);
        int up = solve(grid, i - 1, j, dp);
        return dp[i][j] = grid[i][j] + min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n - 1, m - 1, dp);
    }
};