class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<array<int, 2>>> vis(n, vector<array<int, 2>>(n));
        int cnt = 1;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        auto valid = [&] (int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < n && grid[i][j];
        };


        vector<array<int, 2>> temp;
        function<void(int i, int j)> dfs = [&](int i, int j) {
            vis[i][j][0] = 1;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (valid(nx, ny) && !vis[nx][ny][0]) {
                    cnt++;
                    dfs(nx, ny);
                    temp.push_back({nx, ny});
                }
            }
        };

        int color = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j][0] && grid[i][j]) {
                    cnt = 1;
                    temp.push_back({i, j});
                    dfs(i, j);
                    ans = max(ans, cnt);
                    while (!temp.empty()) {
                        auto cur = temp.back();
                        temp.pop_back();
                        vis[cur[0]][cur[1]][0] = color;
                        vis[cur[0]][cur[1]][1] = cnt;
                    }
                    ++color;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    set<array<int, 2>> s;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (valid(nx, ny)) {
                            s.insert(vis[nx][ny]);
                        }
                    }
                    int sum = 1;
                    for (auto& x : s) {
                        sum += x[1];
                    }
                    ans = max (ans, sum);
                }
            }
        }
        return ans;
    }
};