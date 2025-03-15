class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int low = 1, high = *max_element(candies.begin(), candies.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long cnt = 0;
            for (auto& i : candies) {
                cnt += i / mid;
            }
            if (cnt >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};