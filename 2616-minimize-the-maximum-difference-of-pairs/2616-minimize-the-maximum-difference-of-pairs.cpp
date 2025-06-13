class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(), v.end());
        int n = v.size();
        int low = 0, high = 1e9;

        auto ok = [&](int x) {
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                if (v[i] - v[i - 1] <= x) {
                    cnt++;
                    i++;
                }
            }
            return cnt >= p;
        };

        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ok(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};