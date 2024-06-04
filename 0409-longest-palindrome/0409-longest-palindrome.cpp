class Solution {
public:
    int longestPalindrome(string s) {
        bool odd = false;
        vector<int> f(300);
        for (auto& i : s) {
            f[i]++;
        }
        int ans = 0;
        for (auto& i : f) {
            ans += i / 2;
            if (i & 1) odd = true;
        }
        ans *= 2;
        ans += odd;
        return ans;
    }
};