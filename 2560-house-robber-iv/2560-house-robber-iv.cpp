class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int ans = -1;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        auto ok = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= x) cnt++, i++;
            }
            return cnt >= k;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ok(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};