class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> on(33);

        auto op = [&](int x, int y) {
            for (int i = 0; i < 31; i++) {
                if ((1 << i) & x) {
                    on[i] += y;
                }
            }
        };

        auto ok = [&](int x) {
            for (int i = 0; i < 31; i++) {
                if ((1 << i) & x) {
                    if (on[i]) return false;
                }
            }
            return true;
        };

        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            while (!ok(nums[r])) {
                op(nums[l], -1);
                l++;
            }
            op(nums[r], 1);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};