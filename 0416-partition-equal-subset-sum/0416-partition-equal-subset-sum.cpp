class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot & 1) return false;
        int target = tot / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;
        for (auto& cur : nums) {
            for (int j = target; j >= cur; j--) {
                dp[j] = dp[j] | dp[j - cur];
            }
        }
        return dp[target];
    }
};