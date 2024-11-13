class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int ub = upper_bound(nums.begin() + i, nums.end(), upper - nums[i - 1]) - nums.begin() + i;
            int lb = lower_bound(nums.begin() + i, nums.end(), lower - nums[i - 1]) - nums.begin() + i;
            ans += ub - lb;
        }
        return ans;
    }
};