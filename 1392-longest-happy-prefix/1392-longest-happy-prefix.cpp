class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        int len = 0, i = 1;
        while (i < s.size()) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    i++;
                }
            }
        }
        return s.substr(0, lps.back());
    }
};