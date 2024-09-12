class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> all(26);
        for (auto& i : allowed) {
            all[i - 'a'] = true;
        }
        int ans = 0;
        for (auto& str : words) {
            bool ok = true;
            for (auto& x : str) {
                ok &= all[x - 'a'];
            }
            ans += ok;
        }
        return ans;
    }
};