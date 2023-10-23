class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        bool ok = true;
        int n = str.size();
        for (int i = 0; i < n / 2; i++) {
            ok &= (str[i] == str[n - i - 1]);
        }
        return ok;
    }
};