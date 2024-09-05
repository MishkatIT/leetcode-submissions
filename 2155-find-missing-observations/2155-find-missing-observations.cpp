class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int missing = mean * (n + m) - accumulate(rolls.begin(), rolls.end(), 0);
        if (missing > 6 * n || missing < n) return {};

        vector<int> ans(n, 1);
        missing -= n;
        for (int i = 0; i < n; i++) {
            ans[i] += min(missing, 5);
            missing -= min(missing, 5);
        }
        return ans;
    }
};