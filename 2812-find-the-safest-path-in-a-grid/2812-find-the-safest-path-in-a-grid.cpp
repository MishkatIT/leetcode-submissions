class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>> safeness(n, vector<int>(n, 1e9));

        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {-1, 1, 0, 0};

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    safeness[nx][ny] > safeness[x][y] + 1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<array<int, 3>> pq;
        pq.push({safeness[0][0], 0, 0});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            vis[cur[1]][cur[2]] = true;
            if (cur[1] == n - 1 && cur[2] == n - 1)
                return cur[0];
            for (int d = 0; d < 4; d++) {
                int nx = cur[1] + dx[d], ny = cur[2] + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    pq.push({min(cur[0], safeness[nx][ny]), nx, ny});
                }
            }
        }
        return 0;
    }
};