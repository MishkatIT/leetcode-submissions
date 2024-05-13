class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] != 1) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int one = 0;
            for (int i = 0; i < n; i++) {
                one += (grid[i][j] == 1);
            }
            if (one < n - one) {
                for (int i = 0; i < n; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int pw = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    ans += (1 << pw);
                }
                pw++;
            }
        }
        return ans;
    }
};