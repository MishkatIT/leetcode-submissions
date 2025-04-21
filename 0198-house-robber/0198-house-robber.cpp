class Solution {
public:
    using ll = long long;
    vector<int> dp;
    ll solve (vector<int>& v, int i) {
        if (i == 0) return v[i];
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];
        ll take = v[i] + solve(v, i - 2);
        ll leave = solve(v, i - 1);
        return dp[i] =  max(take, leave);
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 5, -1);
        return solve(nums, nums.size() - 1);
    }
};