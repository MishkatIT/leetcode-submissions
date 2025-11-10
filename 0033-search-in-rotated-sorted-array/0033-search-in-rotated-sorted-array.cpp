class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 1, high = n - 1;
        int mnIdx = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid - 1]) {
                mnIdx = mid;
                break; 
            } else if (nums[mid] > nums.back()) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int idx = -1;
        
        auto fun = [&](int l, int r) {
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] == target) {
                    idx = mid;
                    return;
                } else if (nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        };
        fun(0, mnIdx);
        if (idx != -1) return idx;
        fun(mnIdx, n - 1);
        return idx;
    }
};
