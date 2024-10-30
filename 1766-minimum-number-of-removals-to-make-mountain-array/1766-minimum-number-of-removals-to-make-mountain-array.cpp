class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
        int n = v.size();
        vector<int> lis(n, 1), lds(n, 1);
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (v[j] < v[i]) {
                    mx = max(mx, lis[j]);
                }
            }
            lis[i] += mx;
        }
        for (int i = n - 1; i >= 0; i--) {
            int mx = 0;
            for (int j = i + 1; j < n; j++) {
                if (v[i] > v[j]) {
                    mx = max(mx, lds[j]);
                }
            }
            lds[i] += mx;
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (lis[i] == 1 || lds[i] == 1) continue;
            ans = min(ans, n - lis[i] - lds[i] + 1);
        }
        return ans;
    }
};