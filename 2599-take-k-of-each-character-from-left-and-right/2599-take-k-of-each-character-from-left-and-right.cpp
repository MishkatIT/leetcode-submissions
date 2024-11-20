class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int mx = 0;
        vector<int> f(3);
        for (auto& i : s) f[i -'a']++;
        for (auto& i : f) {
            if (i < k) return -1;
        }

        auto ok = [&]() {
            for (auto& i : f) {
                if (i < k) return 0;
            }
            return 1;
        };

        for (int l = 0, r = 0; r < n; r++) {
            f[s[r] - 'a']--;
            while (!ok()) {
                f[s[l++] - 'a']++;
            }
            mx = max(mx, r - l + 1);
        }
        return n - mx;
    }
};