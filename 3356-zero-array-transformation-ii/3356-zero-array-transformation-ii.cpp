class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int low = 0, high = q;

        auto ok = [&](int mid) {
            vector<int> dif(n + 5);
            for (int i = 0; i < mid; i++) {
                dif[queries[i][0]] += queries[i][2];
                dif[queries[i][1] + 1] -= queries[i][2];
            }
            for (int i = 1; i <= n; i++) dif[i] += dif[i - 1];
            for (int i = 0; i < n; i++) {
                if (nums[i] - dif[i] > 0) return false;
            }
            return true;
        };
        int ans = -1;
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