class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                set<int> s, uni;
                for (int k = i; k <= i + 2; k++) {
                    int sum = 0;
                    for (int l = j; l <= j + 2; l++) {
                        sum += grid[k][l];
                        uni.insert(grid[k][l]);
                    }
                    s.insert(sum);
                }
                for (int l = j; l <= j + 2; l++) {
                    int sum = 0;
                    for (int k = i; k <= i + 2; k++) {
                        sum += grid[k][l];
                        uni.insert(grid[k][l]);
                    }
                    s.insert(sum);
                }
                int d1 = 0, d2 = 0;
                for (int k = 0; k <= 2; k++) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + 2 - k][j + k];
                    uni.insert(grid[i + k][j + k]);
                    uni.insert(grid[i + 2 - k][j + k]);
                }
                s.insert(d1), s.insert(d2);
                bool ok = s.size() == 1;
                ok &= *uni.begin() == 1;
                ok &= *uni.rbegin() == 9;
                if (ok) {
                    ans++;
                }
            }
        }
        return ans;
    }
};