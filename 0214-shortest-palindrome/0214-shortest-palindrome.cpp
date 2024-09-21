class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;

        // Find the longest palindromic prefix
        int mxLen = longestPalindromeStartingFromZero(s);
        if (mxLen == s.size() - 1) return s;

        // Create the reversed part
        string temp = s.substr(mxLen + 1);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }

    int longestPalindromeStartingFromZero(const string& str) {
        string t = "#";
        for (auto& i : str) {
            t += i;
            t += "#";
        }

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0, maxLen = 0;

        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;
            
            // If i is within the right boundary, use the mirror value
            if (i < right) {
                p[i] = min(p[mirror], right - i);
            }

            // Expand around center i
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                ++p[i];
            }

            // Update the right boundary and center
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }

            // Check if the palindrome starts at index 0
            if (i - p[i] == 0) {
                maxLen = max(maxLen, p[i]);
            }
        }
        return maxLen - 1;
    }
};
