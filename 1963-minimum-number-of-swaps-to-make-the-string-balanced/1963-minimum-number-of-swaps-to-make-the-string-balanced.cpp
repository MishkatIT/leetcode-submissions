class Solution {
public:
    int minSwaps(string s) {
        int cnt = (s.front() == ']');
        int two = 0;
        int open = !cnt;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ']') {
                if (open) {
                    open--;
                    continue;
                }
                cnt++;
                if (i & 1) {
                    if (s[i - 1] == s[i]) {
                        two++;
                    }
                }
            } else {
                open++;
            }
        }
        return cnt - two;
    }
};