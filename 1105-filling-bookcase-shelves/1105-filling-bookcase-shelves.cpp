class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 5, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int mx = 0;
            int rem = shelfWidth;
            for (int j = i - 1; j >= 0; j--) {
                rem -= books[j][0];
                mx = max(mx, books[j][1]);
                if (rem >= 0) {
                    dp[i] = min(dp[i], dp[j] + mx);
                }
            }
        }
        return dp[n];
    }
};