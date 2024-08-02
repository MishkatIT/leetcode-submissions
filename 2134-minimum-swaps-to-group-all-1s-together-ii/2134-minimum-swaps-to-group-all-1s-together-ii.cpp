class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int givenOne = count(nums.begin(), nums.end(), 1);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        int ans = 1e9;
        int one = 0;
        for (int i = 0; i < 2 * n; i++) {
            one += (nums[i] == 1);
            if (i + 1 >= givenOne) {
                ans = min(ans, givenOne - one);
                if (i - givenOne + 1 < 2 * n) {
                    one -= (nums[i - givenOne + 1] == 1);
                }
            }
        }
        if (ans == 1e9) ans = 0;
        return ans;
    }
};