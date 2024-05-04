class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mx = 1;
        int st = 0, en = 0;
        for (int x = 0; x < n; x++) {
            int l = x - 1, r = x + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > mx) {
                    mx = r - l + 1;
                    st = l, en = r;
                }
                l--, r++;
            }
            if (x + 1 < n && s[x] == s[x + 1]) {
                int l = x, r = x + 1;
                while(l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > mx) {
                    mx = r - l + 1;
                    st = l, en = r;
                }
                l--, r++;
            }
            } 
        }
        string ans;
        while (st <= en) {
            ans += s[st++];
        }
        return ans;
    }
};