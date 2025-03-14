class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        int l = 1, r = *max_element(v.begin(), v.end()), ans = 0;
        while (l <= r) {
            long long mid = (l + r) / 2, cnt = 0;
            for (auto& i : v) cnt += i / mid;
            if (cnt >= k) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};
