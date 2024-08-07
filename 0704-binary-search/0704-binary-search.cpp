class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int midl = low + (high - low) / 3;
            int midr = high - (high - low) / 3;
            if (nums[midl] == target) {
                return midl;
            } else if (nums[midr] == target) {
                return midr;
            } else if (target < nums[midl]) {
                high = midl - 1;
            } else if (nums[midr] < target) {
                low = midr + 1;
            } else {
                low = midl + 1;
                high = midr - 1;
            }
        }
        return -1;
    }
};