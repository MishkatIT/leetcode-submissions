class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int last = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (last == -1) {
                    last = i;
                } else {
                    swap(s1[last], s1[i]);
                    break;
                }
            }
        }
        return s1 == s2;
    }
};