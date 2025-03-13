class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int inf = 1e9;
        vector<vector<int>> cost(n, vector<int>(m, inf));
        cost[0][0] = 0;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        auto inRange = [&](int i, int j) {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        auto dijkstra = [&]() {
            set<array<int, 3>> s; // cost, i, j
            s.insert({0, 0, 0});
            while (!s.empty()) {
                auto it = s.begin();
                int i = (*it)[1];
                int j = (*it)[2];
                if (i == n - 1 && j == m - 1) {
                    cost[i][j] = (*it)[0];
                }
                s.erase(s.begin());
                for (int dir = 0; dir < 4; dir++) {
                    int nx = dx[dir] + i;
                    int ny = dy[dir] + j;
                    if (inRange(nx, ny)) {
                        int w = grid[nx][ny];
                        if (cost[i][j] + w < cost[nx][ny]) {
                            // s.erase({cost[nx][ny], nx, ny});
                            cost[nx][ny] = cost[i][j] + w;
                            s.insert({cost[nx][ny], nx, ny});
                        }
                    }
                }
            }
        };
        
        dijkstra();
        return cost[n - 1][m - 1];
    }
};