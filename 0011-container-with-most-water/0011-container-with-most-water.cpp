class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 1, high = 1e9;
        int ans = 0;

        auto ok = [&](int x) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mn = min(height[l], height[r]);
                if (mn * (r - l) >= x) return true;
                if (height[l] == mn) l++;
                else r--;
            }
            return false;
        };
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ok(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};