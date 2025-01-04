class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.size();
        for (int c = 'a'; c <= 'z'; c++) {
            int st = n, en = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    st = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == c) {
                    en = i;
                    break;
                }
            }
            set<char> uni;
            for (int i = st + 1; i < en; i++) {
                uni.insert(s[i]);
            }
            ans += uni.size();
        }
        return ans;
    }
};