class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 1;
        int ans = nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid - 1] > nums[mid]) {
                ans = nums[mid];
                break;
            }
            if (nums[0] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};