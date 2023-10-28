class Solution {
public:
    int maxVowels(string str, int k) {
        int n = str.size();
        string window;
        string vowel = "aeiou";
        int mx = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            window += str[i];
            cnt += (vowel.find(str[i]) != string::npos);
            if(i >= k) {
                cnt -= (vowel.find(str[i - k]) != string::npos);
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};