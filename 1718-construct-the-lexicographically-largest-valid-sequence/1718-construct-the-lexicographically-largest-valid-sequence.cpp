class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int len = (n - 1) * 2 + 1;
        vector<int> ans(len);
        vector<bool> taken(n + 5);

        function<bool(int)> dfs = [&](int i)-> bool {
            if (i == len) return true;
            if (ans[i] > 0) return dfs(i + 1);
            for (int x = n; x > 0; x--) {
                if (taken[x]) continue;
                int j = i + x;
                if (x == 1) j = i;
                if (j < len && ans[j] == 0) {
                    ans[i] = ans[j] = x;
                    taken[x] = true;
                    if (dfs(i + 1)) return true;
                    ans[i] = ans[j] = 0;
                    taken[x] = false;
                }
            }
            return false;
        };

        dfs(0);

        return ans;

    }
};