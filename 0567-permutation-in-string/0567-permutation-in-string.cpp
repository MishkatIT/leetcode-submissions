class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(26);
        for (auto& i : s1) {
            f[i - 'a']++;
        }
        int l = 0, r = 0;
        int n = s2.size();
        int tot = s1.size();
        vector<bool> taken(n);
        while (r < n) {
            if (f[s2[r] - 'a'] > 0) {
                f[s2[r] - 'a']--;
                taken[r] = true;
                tot--;
                r++;
            } else {
                if (taken[l]) {
                    f[s2[l] - 'a']++;
                    tot++;
                }
                l++;
            }
            if (tot == 0) return true;
            r = max(l, r);
        }
        return false;
    }
};