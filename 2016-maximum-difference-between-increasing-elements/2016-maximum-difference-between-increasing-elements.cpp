class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        const int inf = 1e9;
        int mn = inf, mx = -inf;
        int ans = -1;
        for (auto& i : nums) {
            if (i <= mn) {
                mn = i;
                mx = -inf;
            } else if (i > mx) {
                mx = i;
            }
            cout << mx << ' ';
            ans = max(ans, mx - mn);
        }
        return ans;
    }
};