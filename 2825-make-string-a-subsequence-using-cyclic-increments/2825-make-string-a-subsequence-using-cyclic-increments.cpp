class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (m > n) return false;
        for (int j = 0, i = 0; j < m; j++) {
            bool ok = false;
            while (i < n) {
                char a = str1[i];
                char b = ((str1[i] - 'a' + 1) % 26) + 'a';
                if (str2[j] == a || str2[j] == b) {
                    ok = true;
                    i++;
                    break;
                }
                i++;
            }
            if (!ok && i >= n) return false;
        }
        return true;
    }
};