class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<bool>> vis(n, vector<bool> (m));
        queue<pair<int, int>> cur;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    vis[i][j] = true;
                    cur.push({i, j});
                }
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};


        auto inRange = [&](int i, int j) {
            return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]); 
        };

        int cnt = 0;
        while (!cur.empty()) {
            int len = cur.size();
            for (int x = 0; x < len; x++) {
                int i = cur.front().first, j = cur.front().second;
                cur.pop();
                ans[i][j] = cnt;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (inRange(nx, ny)) cur.push({nx, ny}), vis[nx][ny] = true;
                }
            }
            cnt++;
        }
        return ans;
    }
};