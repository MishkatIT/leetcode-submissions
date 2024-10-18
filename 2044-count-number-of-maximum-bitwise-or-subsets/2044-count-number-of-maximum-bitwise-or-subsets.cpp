class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (auto& i : nums) {
            mx |= i;
        }
        int ans = 0;
        for (int i = 1; i < (1 << n); i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    temp |= nums[j];
                }
            }
            ans += (temp == mx);
        }
        return ans;
    }
};