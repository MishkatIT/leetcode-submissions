class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums.back()) {
                low = mid + 1;
            } else if (nums[mid] < nums.back()) {
                high = mid;
            }
        }
        return nums[high];
    }
};