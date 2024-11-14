class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans = 1;
        int low = 1, high = 1e5 + 5;
        int m = quantities.size();
        
        auto ok = [&](int mid) {
            int rem = n;
            for (int i = 0; i < m; i++) {
                rem -= ((quantities[i] + mid - 1) / mid);
                if (rem < 0) return false;
            }
            return true;
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