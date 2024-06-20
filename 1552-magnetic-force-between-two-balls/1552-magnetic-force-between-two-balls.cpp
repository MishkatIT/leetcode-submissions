class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0, high = 1e9;
        int ans = 0;
        while (low <= high) {
            int nxt = position.front();
            int mid = low + (high - low) / 2;
            int cnt = 1;
            for (cnt = 1; cnt < m; cnt++) {
                auto it = upper_bound(position.begin(), position.end(), nxt + mid - 1);
                if (it == position.end()) break;
                nxt = *it;
            }
            if (cnt == m) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};