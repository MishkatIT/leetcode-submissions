class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int mxLen = longestPalindromeStartingFromZero(s);
        if (mxLen == s.size() - 1) return s;
        if (mxLen == 0) {
            string temp = s;
            temp.erase(temp.begin());
            reverse(temp.begin(), temp.end());
            return temp + s;
        }
        string temp = s.substr(mxLen + 1);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
int longestPalindromeStartingFromZero(const string& str) {
    string s = "^#"; 
    for (char c : str) {
        s += c;
        s += '#'; 
    }
    s += '$'; 

    int n = s.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; ++i) {
        if (i < right) {
            p[i] = min(right - i, p[2 * center - i]);
        }
        while (s[i + p[i] + 1] == s[i - p[i] - 1]) {
            ++p[i];
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLength = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (i - p[i] == 1) { 
            maxLength = max(maxLength, p[i]);
        }
    }

    return maxLength - 1;
}
};