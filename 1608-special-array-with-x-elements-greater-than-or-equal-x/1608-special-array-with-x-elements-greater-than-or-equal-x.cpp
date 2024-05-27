class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (i == n - (lower_bound(nums.begin(), nums.end(), i) - nums.begin())) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};