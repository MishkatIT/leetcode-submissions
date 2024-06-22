class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n), suf(n);
        pref[0] = 0;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (nums[i - 1] % 2 == 0);
            if (nums[i - 1] & 1) pref[i] = 0;
        }
        suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (nums[i + 1] % 2 == 0);
            if (nums[i + 1] & 1) suf[i] = 0;
        }
        int ans = 0;
        int cnt = 0;
        int l = -1, r = 0;
        while (r < n) {
            if (nums[r] & 1) {
                if (l == -1) l = r;
                cnt++;
            }
            if (cnt == k) {
                ans += 1;
                ans += pref[l] * suf[r];
                ans += pref[l];
                ans += suf[r];
                l++;
                while (l < n && !(nums[l] & 1)) l++;
                cnt--;
            }
            r++;
        }
        return ans;
    }
};