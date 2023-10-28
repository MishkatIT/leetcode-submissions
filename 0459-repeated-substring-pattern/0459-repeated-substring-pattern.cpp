class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; i++) {
            if(n % i == 0) {
                int x = 0;
                bool ok = true;
                for (int j = i; j < n; j++) {
                    if(s[x % i] != s[j]) {
                        ok = false;
                        break;
                    }
                    x++;
                }
                if(ok) {
                    return true;
                }
            }
        }
        return false;
    }
};