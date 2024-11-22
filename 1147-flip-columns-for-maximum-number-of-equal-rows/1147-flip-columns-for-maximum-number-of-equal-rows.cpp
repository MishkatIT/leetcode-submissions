class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string x;
            for (int j = 0; j < m; j++) {
                x += char(matrix[i][j] + '0');
            }
            mp[x]++;
            for (int j = 0; j < m; j++) {
                x[j] = x[j] == '1' ? '0' : '1';
            }
            mp[x]++;
        }
        int ans = 0;
        for (auto& i : mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};