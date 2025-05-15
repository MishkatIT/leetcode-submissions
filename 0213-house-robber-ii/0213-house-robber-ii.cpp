class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return nums.front();
        
        auto fun = [&](int i, int n) {
            if (i + 1 == n) return nums[i];
            vector<int> dp(n);
            dp[i] = nums[i];
            dp[i + 1] = max(nums[i], nums[i + 1]);
            for (int j = i + 2; j < n; j++) {
                dp[j] = max(dp[j - 1], dp[j - 2] + nums[j]);
            }
            return dp[n - 1];
        };

        int ans1 = fun(0, n - 1);
        int ans2 = fun(1, n);
        return max(ans1, ans2);
    }
};