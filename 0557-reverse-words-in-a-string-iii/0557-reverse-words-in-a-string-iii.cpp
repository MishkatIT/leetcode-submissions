class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            string temp;
            while(i < n && s[i] != ' ') {
                temp += s[i++];
            }
            reverse(temp.begin(), temp.end());
            ans += temp + ' ';
        }
        ans.pop_back();
        return ans;
    }
};