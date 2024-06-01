class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int missing = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            missing ^= i;
        }
        for (int i = 0; i < n; i++) {
            missing ^= nums[i];
        }
        return missing;
    }
};