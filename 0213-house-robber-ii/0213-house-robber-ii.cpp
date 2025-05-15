class Solution {
public:
    int rob(vector<int>& v) {

        if (v.size() == 1) return v.front();
        
        auto fun = [](vector<int> v) {
            int n = v.size();
            if (n == 1) return v.front();
            vector<int> dp(n);
            dp[0] = v[0];
            dp[1] = max(v[0], v[1]);
            for (int i = 2; i < n; i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
            }
            return dp[n - 1];
        };

        vector<int> tempA(v.begin(), v.begin() + v.size() - 1);
        int ans1 = fun(tempA);
        vector<int>  tempB(v.begin() + 1, v.end());
        int ans2 = fun(tempB);
        return max(ans1, ans2);
    }
};