class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int j = 31; j >= 0; j--) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                cnt += (nums[i] & (1 << j)) != 0;
            }
            if (cnt % 3) {
                ans |= (1 << j);
            }
        }
        return ans;
    }
};