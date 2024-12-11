class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();

        for (int r = 0, l = 0; r < n; r++) {
            while (nums[r] - nums[l] > 2 * k) l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};