class Solution {
public:
    int minDifference(vector<int>& v) {
        int n = v.size();
        if (n <= 4) return 0;
        sort(v.begin(), v.end());
        int ans = v.back() - v[3];
        ans = min(ans, v[n - 4] - v.front());
        ans = min(ans, v[n - 3] - v[1]);
        ans = min(ans, v[n - 2] - v[2]);
        return ans;
    }
};