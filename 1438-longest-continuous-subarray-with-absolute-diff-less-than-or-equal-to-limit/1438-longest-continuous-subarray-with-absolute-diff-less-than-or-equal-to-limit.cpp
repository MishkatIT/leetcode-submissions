class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            ms.insert(nums[r]);
            if (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[l]));
                l++;
            } else {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};