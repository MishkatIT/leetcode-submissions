class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0, r = 0;
        int curCost = 0;
        int mxLen = 0;
        while (r < n) {
            if (curCost + abs(s[r] - t[r]) <= maxCost) {
                curCost += abs(s[r] - t[r]);
                r++;
                mxLen = max(mxLen, r - l);
            } else {
                curCost -= abs(s[l] - t[l]);
                l++;
            }
        }
        return mxLen;
    }
};