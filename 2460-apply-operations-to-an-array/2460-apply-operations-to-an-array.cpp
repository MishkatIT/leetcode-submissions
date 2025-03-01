class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int last = 0;
        for (int i = 0; i < n; i++) {
            while (last < n && nums[last] != 0) last++;
            if  (nums[i] != 0) {
                if (last < i) swap(nums[i], nums[last]);
            }
        }
        return nums;
    }
};