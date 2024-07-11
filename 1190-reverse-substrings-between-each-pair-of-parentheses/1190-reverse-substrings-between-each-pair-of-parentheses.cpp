class Solution {
public:
    string reverseParentheses(string s) {
        int pos = 0;
        return rev(s, pos);
    }

    string rev(string& str, int& pos) {
        string temp;
        while (pos < (int)str.size()) {
            if (str[pos] == '(') {
                pos++;
                temp += rev(str, pos);
            } else if (str[pos] == ')') {
                pos++;
                reverse(temp.begin(), temp.end());
                return temp;
            } else {
                temp += str[pos++];
            }
        }
        return temp;
    }
};