class Solution {
public:
    char findKthBit(int n, int k) {
        string str = "0";
        for (int i = 2; i <= n; i++) {
            str = str + "1" + rev(flip(str));
        }
        return str[k - 1];
    }
    string flip(string str) {
        for (auto& i : str) {
            if (i == '0') i = '1';
            else i = '0';
        }
        return str;
    }
    string rev(string str) {
        reverse(str.begin(), str.end());
        return str;
    }
};