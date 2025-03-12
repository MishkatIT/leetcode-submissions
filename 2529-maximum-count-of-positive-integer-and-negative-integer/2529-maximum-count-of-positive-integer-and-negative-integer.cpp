class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int l = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int n = nums.size();
        if (r < n && nums[r] < 0) r++;
        return max(l, (int)nums.size() - r);
    }
};