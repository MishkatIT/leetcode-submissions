class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        --k;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i < k) continue;
            bool ok = true;
            ok &= (nums[i] - k == nums[i - k]);
            long long a = nums[i - k] - 1, b = nums[i];
            long long tsum = b * (b + 1) / 2 - a * (a + 1) / 2;
            ok &= (tsum == sum);
            if (ok) ans[i - k] = nums[i];
            sum -= nums[i - k];
        }
        return ans;
    }
};