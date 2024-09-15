class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        map<int, int> have; //hash, pos
        have[0] = -1;
        string v = "aeiou";
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (v.find(s[i]) == string::npos) {
                ans = max(ans, i - have[cur]);
            } else {
                int x = s[i] - 'a';
                cur ^= (1 << x);
                if (have.find(cur) == have.end()) {
                    have[cur] = i;
                } else {
                    ans = max(ans, i - have[cur]);
                }
            }
        }
        return ans;
    }
};