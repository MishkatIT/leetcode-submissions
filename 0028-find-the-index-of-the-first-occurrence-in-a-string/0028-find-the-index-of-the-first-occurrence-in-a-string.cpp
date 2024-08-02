
void computeLPS(int m, string& ptr, vector<int>& lps) {
    int len = 0, i = 1;
    while (i < m) {
        if (ptr[i] == ptr[len]) {
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
}


int KMP(string& str, string& ptr) {
    int n = str.length(), m = ptr.length();
    vector<int> lps(m);
    computeLPS(m, ptr, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (str[i] == ptr[j]) {
            i++, j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m) {
            return (i - j);
        }
    }
    return -1;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMP(haystack, needle);
    }
};