class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(3, -1)));
        return solve(n, 1, 2, dp); // n, absent, late
    }
    
    const int mod = 1e9 + 7;
    using ll = long long;
    
    ll solve(int n, int a, int l, vector<vector<vector<ll>>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][a][l] != -1) {
            return dp[n][a][l];
        }
        ll ans = 0;

        // Present
        ans = (ans + solve(n - 1, a, 2, dp)) % mod;
        
        // Absent
        if (a > 0) {
            ans = (ans + solve(n - 1, a - 1, 2, dp)) % mod;
        }

        // Late
        if (l > 0) {                                
            ans = (ans + solve(n - 1, a, l - 1, dp)) % mod;
        }

        return dp[n][a][l] = ans % mod;
    }
};
