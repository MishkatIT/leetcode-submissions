class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ans = 0;
        int i = 0, j = 0;
        int lena = version1.length(), lenb = version2.length();
        while(i < lena || j < lenb) {
            string tempa, tempb;
            while (i < lena && version1[i] != '.') {
                if (tempa.size() > 0) {
                    tempa += version1[i];
                } else if (version1[i] != '0') {
                    tempa += version1[i];
                }
                i++;
            }
            i++;
            while (j < lenb && version2[j] != '.') {
                if (tempb.size() > 0) {
                    tempb += version2[j];
                } else if (version2[j] != '0') {
                    tempb += version2[j];
                }
                j++;
            }
            j++;
            if (tempa.size() < tempb.size()) {
                ans = -1;
                break;
            } else if (tempa.size() > tempb.size()) {
                ans = 1;
                break;
            }
            if (tempa > tempb) {
                ans = 1;
                break;
            } else if (tempa < tempb) {
                ans = -1;
                break;
            }
        }
        return ans;
    }
};