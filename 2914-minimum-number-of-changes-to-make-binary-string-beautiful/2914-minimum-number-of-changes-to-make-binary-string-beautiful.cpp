class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (i + 1 < s.size() && s[i] != s[i + 1]) {
                changes++;
            }
        }
        return changes;
    }
};
