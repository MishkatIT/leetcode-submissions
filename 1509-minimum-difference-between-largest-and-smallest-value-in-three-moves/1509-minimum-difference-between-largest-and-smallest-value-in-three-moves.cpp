class Solution {
public:
    int minDifference(vector<int>& v) {
        int n = v.size();
        if (n <= 4) return 0;
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            ans = min(ans, v[n - 4 + i] - v[i]);
        }
        return ans;
    }
};