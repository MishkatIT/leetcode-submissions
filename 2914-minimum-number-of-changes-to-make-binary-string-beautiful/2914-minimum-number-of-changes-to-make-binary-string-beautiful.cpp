class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++, cnt++;
            ans += (cnt & 1);
            i = j;
            if (cnt % 2 == 0) i--;
        }
        return ans;
    }
};