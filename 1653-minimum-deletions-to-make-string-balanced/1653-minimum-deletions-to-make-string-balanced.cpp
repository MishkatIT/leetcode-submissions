class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> prefb(n), sufa(n);
        for (int i = 1; i < n; i++) {
            prefb[i] = prefb[i - 1] + (s[i - 1] == 'b');
        }
        for (int i = n - 2; i >= 0; i--) {
            sufa[i] = sufa[i + 1] + (s[i + 1] == 'a');
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans = min(ans, prefb[i] + sufa[i]);
        }
        return ans;
    }
};