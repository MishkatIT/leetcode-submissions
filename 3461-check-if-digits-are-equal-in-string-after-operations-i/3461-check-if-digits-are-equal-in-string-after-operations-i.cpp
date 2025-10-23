class Solution {
public:
    bool hasSameDigits(string s) {
        while ((int)s.size() > 2) {
            for (int i = 0; i < (int)s.size() - 1; i++) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                s[i] = ((a + b) % 10) + '0';
            }
            s.pop_back();
            cout << s << '\n';
        }
        return s[0] == s[1];
    }
};