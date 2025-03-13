class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i];
            if (temp > 0) temp = 0;
            ans = max(ans, -temp);
        }
        temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i];
            if (temp < 0) temp = 0;
            ans = max(ans, temp);
        }
        return ans;
    }
};