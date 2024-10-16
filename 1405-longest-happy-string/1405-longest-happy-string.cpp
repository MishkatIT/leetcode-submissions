class Solution {
public:
    string ans;
    vector<pair<int, int>> v;
    string longestDiverseString(int a, int b, int c) {
        v = {{a, 0}, {b, 1}, {c, 2}};
        vector<int> cur = {2, 2, 2};
        solve(cur);
        return ans;
    }
    void solve(vector<int> cur) {
        sort(v.rbegin(), v.rend());
        for (auto& i : v) {
            if (cur[i.second] && i.first > 0) {
                ans += char(i.second + 'a');
                cur[i.second]--;
                i.first--;
                if (i.second != 0) cur[0] = 2;
                if (i.second != 1) cur[1] = 2;
                if (i.second != 2) cur[2] = 2;
                solve(cur);
            }
        }
        return;
    }
};