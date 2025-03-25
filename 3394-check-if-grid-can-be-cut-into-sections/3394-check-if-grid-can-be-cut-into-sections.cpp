class Solution {
public:
    bool checkValidCuts(int nn, vector<vector<int>>& rec) {
        
        int n = rec.size();

        auto check = [&] (auto& v) {
            sort(v.begin(), v.end(), [&](auto& a, auto& b) {
                return(a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
            });
            int cnt = 0;
            int mx = 0;
            for (int i = 0; i < n; i++) {
                if (v[i][0] >= mx) cnt++;
                mx = max(mx, v[i][1]); 
            }
            return cnt;
        };

        for (int x = 0; x < 2; x++) {
            vector<array<int, 2>> temp;
            for (int i = 0; i < n; i++) {
                int a = rec[i][x], b = rec[i][x + 2];
                if (a > b) swap(a, b);
                temp.push_back({a, b});
            }
            if (check(temp) >= 3) return true;
        }
        return false;
    }
};