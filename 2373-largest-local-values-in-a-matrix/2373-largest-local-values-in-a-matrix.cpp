class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < n; j++) {
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        maxLocal[i][j] = max(maxLocal[i][j], grid[k][l]);
                    }
                }
            }
        }
        return maxLocal;
    }
};