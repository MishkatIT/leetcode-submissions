class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 1e7;
        int cur = 0;
        vector<int> f(35);
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            cur |= nums[i];
            for (int bit = 0; bit < 32; bit++) {
                if ((1 << bit) & nums[i]) f[bit]++;
            }
            while (cur >= k) {
                if (j >= n) break;
                ans = min(ans, i - j + 1);
                for (int bit = 0; bit < 32; bit++) {
                    if ((1 << bit) & nums[j]) f[bit]--;
                }
                j++;
                cout << ans << ' ';
                int temp = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (f[bit]) {
                        temp |= (1 << bit);
                    }
                }
                cur = temp;
            }
        }
        if (ans == 1e7) return -1;
        return max(ans, 1);
    }
};