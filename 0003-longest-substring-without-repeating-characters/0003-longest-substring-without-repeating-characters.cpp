class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> have;
        int len = 0;
        int idx = 0;
        int ans = 0;
        for (auto& i : s) {
            while (have[i]) {
                len--;
                have[s[idx]]--;
                idx++;
            }
            have[i] = 1;
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};