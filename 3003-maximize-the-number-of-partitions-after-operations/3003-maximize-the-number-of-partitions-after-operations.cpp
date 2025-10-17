class Solution {
public:
    map<long long, int> dp;

    long long makeKey(int i, bool used, int mask) {
        return ((long long)i << 27) | ((long long)used << 26) | mask;
    }

    int solve(int i, string& str, int k, bool used, int mask) {
        if (i == str.size()) return 0;
        long long key = makeKey(i, used, mask);
        if (dp.count(key)) return dp[key];

        int mx = 0;
        int cur = str[i] - 'a';
        int nmask = mask | (1 << cur);

        if (__builtin_popcount(nmask) <= k)
            mx = max(mx, solve(i + 1, str, k, used, nmask));
        else
            mx = max(mx, 1 + solve(i + 1, str, k, used, 1 << cur));

        if (!used) {
            for (int j = 0; j < 26; j++) {
                if (j == cur) continue;
                int altMask = mask | (1 << j);
                if (__builtin_popcount(altMask) <= k)
                    mx = max(mx, solve(i + 1, str, k, true, altMask));
                else
                    mx = max(mx, 1 + solve(i + 1, str, k, true, 1 << j));
            }
        }
        return dp[key] = mx;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        dp.clear();
        return 1 + solve(0, s, k, false, 0);
    }
};
