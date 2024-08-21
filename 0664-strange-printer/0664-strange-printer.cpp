class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
         return solve(0, n - 1, s, dp);
    }

    int solve(int i, int n, string& str, vector<vector<int>>& dp) {
        if (i == n) return 1;
        if (dp[i][n] != -1) return dp[i][n];
        int ans = 10000000;
        for (int j = i; j < n; j++) {
            ans = min(ans, solve(i, j, str, dp) + solve(j + 1, n, str, dp));
        }
        if (str[i] == str[n]) ans--;
        return dp[i][n] = ans;
    }
};