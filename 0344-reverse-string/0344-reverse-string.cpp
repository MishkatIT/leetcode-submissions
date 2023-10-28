class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp = s[0];
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
        {
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = temp;
            temp = s[i + 1];
        }
    }
};