class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        auto inRange = [&](int i, int j) {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };
        const int inf = 1e9;
        vector<vector<int>> dist(n, vector<int>(m, inf));
        dist[0][0] = 0;
        function<void()> dijkstra = [&]() {
            set<array<int, 3>> s; // time, i, j
            s.insert({0, 0, 0});
            while (!s.empty()) {
                int time = (*s.begin())[0];
                int i = (*s.begin())[1];
                int j = (*s.begin())[2];
                s.erase(s.begin());
                bool ok = false;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (inRange(nx, ny)) {
                        if (grid[nx][ny] <= dist[i][j] + 1) {
                            ok = true; break;
                        } 
                    }
                }
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (inRange(nx, ny)) {
                        if (dist[i][j] + 1 >= grid[nx][ny]) {
                            if (dist[i][j] + 1 < dist[nx][ny]) {
                                s.erase({dist[nx][ny], nx, ny});
                                dist[nx][ny] = dist[i][j] + 1;
                                s.insert({dist[nx][ny], nx, ny});
                            }
                        } else if (ok) {
                            int need = grid[nx][ny] - time - 1;
                            int cur = time + (need + 1) / 2 * 2;
                            s.erase({dist[nx][ny], nx, ny});
                            dist[nx][ny] = cur + 1;
                            s.insert({dist[nx][ny], nx, ny});
                        }
                    }
                }
            }
        };
        
        dijkstra();
        return dist[n - 1][m - 1] == inf ? -1 : dist[n - 1][m - 1];
    }
};