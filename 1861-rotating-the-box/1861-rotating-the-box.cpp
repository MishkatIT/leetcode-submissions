class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (box[i][j] == '#') {
                    cnt++;
                    box[i][j] = '.';
                }
                if (box[i][j] == '*' || j == m - 1) {
                    int k = j;
                    if (box[i][j] == '*') k--;
                    while (cnt > 0 && k >= 0) {
                        box[i][k] = '#';
                        cnt--;
                        k--;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][i] = box[n - i - 1][j];
            }
        }
        return ans;
    }
};