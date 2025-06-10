class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26);
        for (auto& i : s) {
            f[i - 'a']++;
        }
        int odd = 0, even = 1e9;
        for (int i = 0; i < 26; i++) {
            if (!f[i]) continue;
            if (f[i] & 1) {
                odd = max(odd, f[i]);
            } else {
                even = min(even, f[i]);
            }
        }
        return odd - even;
    }
};