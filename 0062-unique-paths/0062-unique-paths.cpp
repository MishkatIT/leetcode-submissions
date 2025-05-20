class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m, 1), cur(m);
        for (int i = 1; i < n; i++) {
            cur[0] = 1;
            for (int j = 1; j < m; j++) {
                cur[j] = prev[j] + cur[j - 1];
            }
            prev = cur;
        }
        return prev[m - 1];
    }
};