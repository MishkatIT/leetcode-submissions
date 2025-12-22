class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int full = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        int cur = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            cur += nums[i];
            ans += (full - cur - cur) % 2 == 0;
        }
        return ans;
    }
};