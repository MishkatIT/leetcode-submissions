class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for (auto& i : s) {
            if ('0' <= i && i <= '9') x += i;
            if ('a' <= i && i <= 'z') x += i;
            if ('A' <= i && i <= 'Z') x += i - 'A' + 'a';
        }
        string y = x;
        reverse(y.begin(), y.end());
        return x == y;
    }
};