class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int n = s.size();
        while (i < n) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                i++;
            }
            if (j >= n) break;
        }
        return (t.size() - j);
    }
};