class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) return false;
        int x = total / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 5, vector<bool>(x + 5));
        for (int i = 0; i < n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                bool skip = dp[i - 1][j];
                bool take = false;
                if (j - nums[i - 1] >= 0) {
                    take = dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] = take | skip;
            }
        }
        return dp[n][x];
    }
};