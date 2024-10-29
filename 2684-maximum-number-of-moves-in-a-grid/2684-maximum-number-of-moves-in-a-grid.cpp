class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n) ;
        for (auto& r : dp) {
            r.resize(m);
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dfs(i, 0, grid));
        }
        return mx - 1;
    }

    bool valid(int i, int j, int ni, int nj, vector<vector<int>>& grid) {
        return (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[i][j] < grid[ni][nj]);
    }
    int dx[3] = {-1, 0, +1};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int mx = 0;
        for (int x = 0; x < 3; x++) {
            int ni = i + dx[x], nj = j + 1;
            if (valid(i, j, ni, nj, grid)) {
                if (dp[ni][nj]) {
                    mx = max(mx, dp[ni][nj]);
                } else {
                    mx = max(mx, dfs(ni, nj, grid));
                }
            }
        }
        dp[i][j] = mx;
        return mx + 1;
    }

};