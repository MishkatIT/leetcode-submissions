class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ) {
            int cnt = 0;
            if (nums[i] == mx) {
                    while (i < n && nums[i] == mx) {
                    ++cnt;
                    ++i;
                }
            } else ++i;
            ans = max(ans, cnt);
        }
        return ans;
    }
};