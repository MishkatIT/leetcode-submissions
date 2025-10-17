class Solution {
public:

    using ll = long long;
    
    ll make(ll i, ll used, ll mask) {
        return mask | (used << 26) | (i << 27);
    };

    map<ll, int> dp;

    int solve(int i, string& str, int k, bool used, int mask) {
        if (i == str.size()) return 0;
        ll key = make(i, used, mask);
        if (dp.count(key)) return dp[key];
        int mx = 0;
        int cur = str[i] - 'a';
        int nmask = mask | (1 << cur);
        int setbit = __builtin_popcount(nmask);
        if (setbit <= k) {
            mx = max(mx, solve(i + 1, str, k, used, nmask));
        } else {
            mx = max(mx, 1 + solve(i + 1, str, k, used, 1 << cur));
        }

        if (!used) {
            for (int j = 0; j < 26; j++) {
                int nmask = mask | (1 << j);
                int setbit = __builtin_popcount(nmask);
                if (setbit <= k) {
                    mx = max(mx, solve(i + 1, str, k, true, nmask));
                } else {
                    mx = max(mx, 1 + solve(i + 1, str, k, true, 1 << j));
                }
            }
        }
        return dp[key] = mx;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + solve(0, s, k, false, 0);
    }
};