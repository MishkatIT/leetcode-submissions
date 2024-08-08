class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        int cnt = 0;
        vector<vector<int>> ans;
        int lr = 1;
        int ud = 0;

        auto check = [&](int i, int j) {
            bool ok = (i >= 0 & i < rows & j >= 0 & j < cols);
            if (ok) ans.push_back({i, j}), cnt++;
        };

        while (cnt < total) {
            int j = cStart + (cnt > 0);
            cStart += lr;
            while (j <= cStart) {
                check(rStart, j);
                j++;
            }
            lr++;
            ud++;

            int i = rStart + 1;
            rStart += ud;
            while (i <= rStart) {
                check(i, cStart);
                i++;
            }

            j = cStart - 1;
            cStart -= lr;
            while (j >= cStart) {
                check(rStart, j);
                j--;
            }
            lr++;
            ud++;

            i = rStart - 1;
            rStart -= ud;
            while (i >= rStart) {
                check(i, cStart);
                i--;
            }
        }
        return ans;
    }
};