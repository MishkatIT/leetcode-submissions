class Solution {
public:
    int countDays(int days, vector<vector<int>>& x) {
        auto cmp = [&](auto& a, auto& b) {
            return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
        };
        sort(x.begin(), x.end(), cmp);
        int ans = 0, last = 1, mx = 0;
        for (auto& i : x) {
            if (i[0] > mx + 1) ans += i[0] - mx - 1;
            mx = max(mx, i[1]);
        }
        if (mx < days) ans += days - mx;
        return ans;
    }
};