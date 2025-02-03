class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int ans = 1;
        int n = v.size();
        for (int i = 0, cnt = 1; i + 1 < n; i++) {
            if (v[i] < v[i + 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else cnt = 1;
        }
        for (int i = n - 1, cnt = 1; i > 0; i--) {
            if (v[i] < v[i - 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else cnt = 1;
        }
        return ans;
    }
};