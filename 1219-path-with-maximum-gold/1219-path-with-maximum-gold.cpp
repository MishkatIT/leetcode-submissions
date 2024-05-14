class Solution {
private:
int dy[4] = {+0, +0, -1, +1};
int dx[4] = {+1, -1, +0, +0};
int dfs(vector<vector<int>>& grid, int r, int c, int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) return 0;
    int mx = grid[i][j];
    int old = grid[i][j];
    grid[i][j] = 0;
    for (int d = 0; d < 4; d++) {
        mx = max(mx, old + dfs(grid, r, c, i + dx[d], j + dy[d]));
    }
    grid[i][j] = old;
    return mx;
}

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int mx = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] != 0) {
                    mx = max(mx, dfs(grid, r, c, i, j));
                }
            }
        }
        return mx;
    }
};