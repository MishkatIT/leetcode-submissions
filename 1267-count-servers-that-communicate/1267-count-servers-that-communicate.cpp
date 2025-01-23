class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        set<pair<int, int>> s;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> temp;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    temp.push_back({i, j});
                }
            }
            if (temp.size() > 1) {
                for (auto& j : temp) {
                    s.insert(j);
                }
            }
        }
        for (int j = 0; j < m; j++) {
            vector<pair<int, int>> temp;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    temp.push_back({i, j});
                }
            }
            if (temp.size() > 1) {
                for (auto& j : temp) {
                    s.insert(j);
                }
            }
        }
        return s.size();
    }
};