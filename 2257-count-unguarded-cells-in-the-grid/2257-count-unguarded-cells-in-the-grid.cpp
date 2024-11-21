class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(m, n);
        vector<vector<int>> vis(n, vector<int>(m, false));
        map<pair<int, int>, bool> g;
        map<pair<int, int>, bool> w;
        for (auto& i : guards) {
            g[{i[0], i[1]}] = true;
        }
        for (auto& i : walls) {
            w[{i[0], i[1]}] = true;
        }

        for (int i = 0; i < n; i++) {
            bool ok = false; 
            for (int j = 0; j < m; j++) {
                if (g[{i, j}]) ok = true;
                if (w[{i, j}]) ok = false;
                vis[i][j] += ok;
            }
            ok = false; 
            for (int j = m - 1; j >= 0; j--) {
                if (g[{i, j}]) ok = true;
                if (w[{i, j}]) ok = false;
                vis[i][j] += ok;
            }
        }
        for (int j = 0; j < m; j++) {
            bool ok = false; 
            for (int i = 0; i < n; i++) {
                if (g[{i, j}]) ok = true;
                if (w[{i, j}]) ok = false;
                vis[i][j] += ok;
            }
            ok = false; 
            for (int i = n - 1; i >= 0; i--) {
                if (g[{i, j}]) ok = true;
                if (w[{i, j}]) ok = false;
                vis[i][j] += ok;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!w[{i, j}] && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};