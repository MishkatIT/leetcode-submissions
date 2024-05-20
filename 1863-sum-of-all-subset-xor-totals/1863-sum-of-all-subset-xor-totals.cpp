class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int temp = 0;
            for (int j = 0; j < 13; j++) {
                if ((i & (1 << j)) != 0) {
                    temp ^= nums[j];
                }
            }
            sum += temp;
        }
        return sum;
    }
};