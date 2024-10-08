class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;
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
        int mx = 0;
        string t = "#";
        for (auto& i : str) {
            t += i;
            t += "#";
        }
        int n = t.size();
        vector<int> p(n);
        int center = 0, right = 0;
        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;
            if (i < right) {
                p[i] = min(p[mirror], right - i);
            }
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
             if (p[i] - i == 0) {
                mx = p[i];
            }
        }
        
        return mx - 1;
    }



};