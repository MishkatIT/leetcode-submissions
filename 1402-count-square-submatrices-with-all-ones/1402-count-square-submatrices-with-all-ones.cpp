class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool ok = true;
                for (int k = 0; ; k++) {
                    if (!ok) break;
                    int curi = i + k;
                    int curj = j + k;
                    if (curi < n && curj < m) {
                        for (int x = j; x <= curj; x++) {
                            ok &= matrix[curi][x] == 1;
                        }
                        for (int x = i; x <= curi; x++) {
                            ok &= matrix[x][curj] == 1;
                        }
                        if (ok) ans++;
                        else break;
                    } else break;
                }
            }
        }
        return ans;
    }
};