class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        auto bit = [&](int x) {
            return __builtin_popcount(x);
        };
        auto ok = [&](int a, int b) {
            return (bit(a) == bit(b) && a > b);
        };
        int n = nums.size();
        for (int x = 0; x < (n * n); x++) {
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i] > nums[i + 1]) {
                    if (ok(nums[i], nums[i + 1])) swap(nums[i], nums[i + 1]);
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};