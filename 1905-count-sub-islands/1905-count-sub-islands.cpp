class Solution {
public:
    int n, m;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));

        auto valid = [&] (int i, int j) {
            return (i >= 0 && i < n && j >= 0 && j < m && grid2[i][j]);
        };

        int dy[4] = {0, 0, -1, +1};
        int dx[4] = {+1, -1, 0, 0};

        function<bool(int, int)> dfs = [&](int i, int j) {
            vis[i][j] = true;
            bool ok = (grid1[i][j] == 1);
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (valid(nx, ny) && !vis[nx][ny]) {
                   ok &= dfs(nx, ny);
                }
            }
            return ok;
        };

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j]) {
                    cnt += dfs(i, j);
                }
            }
        }
        return cnt;
    }
};
